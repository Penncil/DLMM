
DLMM: Lossless One-shot Distributed Linear Mixed Model for a Multisite International Study of COVID-19 Hospitalization Length of Stay
==============================================


## Outline
1. Description
2. DLMM workflow
3. Package requirements
4. Install package
5. Run DLMM
6. Results and running time
7. How to run DLMM on your data?

## Description
This README is prepared for journal peer review of the Distributed Linear Mixed Model (DLMM) paper. The proposed DLMM algorithm can be used in multi-center studies and requires each site to communicate only some aggregate data (AD), but achieves lossless estimates (i.e. identical estimates as if we have all the patients-level data).

To demonstrate its usage and lossless property (as in Section 2 of the paper), we use a simulated data of 1000 patients from 3 sites, and analyze the association of length of stay (LOS) with age, sex and lab test. LMM allows heterogeneous sites as it assumes site-specific random effects (intercepts).  

DLMM is a distributed algorithm under [PDA](https://github.com/Penncil/pda) (Privacy-preserving Distributed Algorithms) framework. The package in this repo is for the whole PDA framework, including other distributed algorithms. 

## DLMM workflow (Figure 2)
![](workflow.png)

## Package Requirements
- A database with clear and consistent variable names
- R version: R (>= 3.5.0)
- On Windows: download and install [RTools](http://cran.r-project.org/bin/windows/Rtools/) 
- To install the `pda` package, make sure you have cpp compiler as `pda` requires [Rcpp](https://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-FAQ.pdf). This is a technical requirement for `pda` and not related to DLMM algorithm.

## Install package

To implement DLMM algorithms, we need to install the `pda` package.  

1. In RStudio, create a new project: File -> New Project... -> New Directory -> New Project. 

2. Execute the following R code: 

```r
# Install the latest version via github (recommended):
install.packages("devtools")
library(devtools)
devtools::install_github("penncil/pda")
 
# Or you can install from CRAN:
install.packages("pda")

```

The installation time is about 20 secs via github and 5 secs via CRAN (normal personal computer). 

In the toy example below we aim to analyze the association of hospitalization length of stay (LOS) with age, sex and lab test using linear mixed model, assuming site-specific random intercepts. We demonstrate using PDA DLMM can obtain identical estimation as the pooled analysis. 

We run the example in local directory. In actual collaboration, account/password for `pda` server will be assigned to the sites at the server https://pda.one. Each site can access via web browser to check the communication of the summary stats.

 
### *Run DLMM example with code*

Step 0: load related R packages and prepare sample data

```r
## load packages
require(pda) 
require(lme4) 

## sample data
?LOS
data(LOS)  

## split the data to 3 separate sets (patient-level data)
LOS_split <- split(LOS, LOS$site)
 
``` 

Step 1: DLMM Initialization

```r
## setup pda control
control <- list(project_name = 'Length of stay study',
                step = 'initialize',
                sites = c('site1', 'site2', 'site3'),
                heterogeneity = TRUE,
                heterogeneity_effect = 'random',
                model = 'DLM',
                family = 'gaussian',
                outcome = "los",
                variables = c('age', 'sex', 'lab'), 
                optim_maxit = 100,
                lead_site = 'site1',
                upload_date = as.character(Sys.time()) )

 
## specify your working directory, default is the current working dir
mydir <- getwd()   
pda(site_id = 'site1', control = control, dir = mydir)
# you now can see control.json in the working dir


## DO NOT RUN: in actual collaboration, account/password for pda server will be assigned, thus:
# pda(site_id = 'site1', control = control, uri = 'https://pda.one', secret='abc123')
## you can also set your environment variables, and no need to specify them in pda:
# Sys.setenv(PDA_USER = 'site1', PDA_SECRET = 'abc123', PDA_URI = 'https://pda.one')
# pda(site_id = 'site1', control = control)


## site3 communicate its AD: after review, enter "1" to allow tranferring AD 
pda(site_id = 'site3', ipdata = LOS_split[[3]], dir=mydir)
# you now can see site3_initialize.json in the working dir

## site2 communicate its AD: after review, enter "1" to allow tranferring AD   
pda(site_id = 'site2', ipdata = LOS_split[[2]], dir=mydir)
# you now can see site2_initialize.json in the working dir

## site1 communicate its AD: after review, enter "1" to allow tranferring AD   
pda(site_id = 'site1', ipdata = LOS_split[[1]], dir=mydir)
# you now can see site3_initialize.json in the working dir
# all the AD are ready, control.json is also automatically updated to the next step

``` 

DLMM STEP 2: estimation using AD

```r  
pda(site_id = 'site1', ipdata = LOS_split[[1]], dir=mydir)
# you now can see site1_estimate.json in the working dir

## get the estimated results
config <- getCloudConfig(site_id = 'site1', dir=mydir)
fit.dlmm <- pdaGet(name = 'site1_estimate', config = config)
```


Compare with pooled analysis:

```r 
## fit LMM using pooled data, assuming random intercepts for each site
fit.pool <- lme4::lmer(los~age+sex+lab+(1|site), REML = F, data=LOS)

# fixed effects (intercept, age, sex, lab) and their sd 
cbind(b.pool = round(summary(fit.pool)$coef[,1], 4),
      b.dlmm = c(fit.dlmm$bhat),      
      sd.pool = round(summary(fit.pool)$coef[,2], 4),  
      sd.dlmm = fit.dlmm$sebhat)  

# variance components (var of random intercepts, and random error)
cbind(vc.pool=round(data.frame(summary(fit.pool)$varcor)$vcov, 4),
      vc.dlmm=round(c(fit.dlmm$Vhat, fit.dlmm$sigmahat^2),4) )

# random intercepts (BLUP) of each sites
cbind(u.pool = round(ranef(fit.pool)$site, 4),
      u.dlmm = c(fit.dlmm$uhat))

```


## Results and Running time

Fixed effect (identical to 2 digits):

|             | b.pool  | b.dlmm  | sd.pool | sd.dlmm|
|-------------|---------|---------|---------|--------|
| (Intercept) | 8.1428  | 8.1431  | 0.4926  | 0.4928 |
| ageold      | 0.9217  | 0.9217  | 0.2840  | 0.2848 |
| ageyoung    | -0.9825 | -0.9825 | 0.3478  | 0.3487 |
| sexM        | 0.4533  | 0.4532  | 0.2545  | 0.2552 |
| lab         | 0.1020  | 0.1020  | 0.0043  | 0.0043 |

Variance components (identical to 2 digits):

|  vc.pool    | vc.dlmm |
|-------------|---------|
| 0.4764      | 0.4758  |
| 16.1371     | 16.2183 |

Random effect (BLUP) (identical to 2 digits):

|        | (Intercept) | u.dlmm  |
|--------|-------------|---------|
| site1  | -0.0400     | -0.0403 |
| site2  | 0.8070      | 0.8063  |
| site3  | -0.7671     | -0.7661 |


The running time in each site in this demo is about 4-5 secs. 


## How to run DLMM on your data?

* Get the data ready, which requires no missing values and clear variable names.
* Define the `control` by specifying the model, data, outcome, variables, site names, and local site.
* Directly run `pda` function as illustrated above.
