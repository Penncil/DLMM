
DLMM: Lossless One-shot Distributed Linear Mixed Model for a Multisite International Study of COVID-19 Hospitalization Length of Stay
==============================================


## Outline
1. Description
2. DLMM workflow
3. Package requirements
4. Install package
5. Run DLMM
6. Results and running time

## Description
DLMM is a distributed algorithm under [PDA](https://github.com/Penncil/pda) (Privacy-preserving Distributed Algorithms) framework. The package in this repo is for the whole PDA framework, including other distributed algorithms. This README will focus on the implementation of DLMM only.

## DLMM workflow
![](workflow.png)

## Package Requirements
- A database with clear and consistent variable names
- On Windows: download and install [RTools](http://cran.r-project.org/bin/windows/Rtools/) 
- For ODAC (One-shot distributed algorithm for Cox regression) in the pda package, make sure you have cpp compiler as ODAC requires [Rcpp](https://cran.r-project.org/web/packages/Rcpp/vignettes/Rcpp-FAQ.pdf).


## Install package

To implement DLMM algorithms, we need to install the `pda` package. There are several ways in which one could install the `pda` package. 

1. In RStudio, create a new project: File -> New Project... -> New Directory -> New Project. 

2. Execute the following R code: 

```r
# Install the latest version of PDA in R:
install.packages("pda")
library(pda)

# Or you can install via github:
install.packages("devtools")
library(devtools)
devtools::install_github("penncil/pda")
library(pda)
```

In the toy example below we aim to analyze the association of hospitalization length of stay (LOS) with age, sex and lab test using linear model, data(LOS) is simulated and assumed to come from 3 sites: 'site1', 'site2', 'site3' we demonstrate using PDA DLM can obtain identical estimation as the pooled analysis. 3 models are tested:

* Linear model ignoring site-effect
* Linear model with fixed site-effect
* Linear model with random site-effect (Linear mixed model)

We run the example in local directory. In actual collaboration, account/password for pda server will be assigned to the sites at the server https://pda.one. Each site can access via web browser to check the communication of the summary stats.

### *Run DLMM example with demo()*

```r
demo(DLM)
``` 

### *Run DLMM example with code*

Step 0: load related R packages and prepare sample data

```r
## load packages
require(lme4)
require(minqa)
require(data.table)
require(pda) 

## sample data
data(LOS)  

## create 3 sites, split the data
sites = c('site1', 'site2', 'site3')
LOS_split <- split(LOS, LOS$site)

## fit logistic reg using pooled data
fit.pool <- glm(status ~ age + sex, family = 'binomial', data = lung2)

``` 

Step 1: Initialization

```r
# ############################  STEP 1: initialize  ###############################
control <- list(project_name = 'Length of stay study',
                step = 'initialize',
                sites = sites,
                heterogeneity = FALSE,
                # heterogeneity_effect = 'fixed',
                model = 'DLM',
                family = 'gaussian',
                outcome = "los",
                variables = c('age', 'sex', 'lab'),
                # variables_heterogeneity = c('Intercept'),
                optim_maxit = 100,
                lead_site = 'site1',
                upload_date = as.character(Sys.time()) )
		
		
## run the example in local directory:
## specify your working directory, default is the tempdir
mydir <- getwd()  # tempdir()
## assume lead site1: enter "1" to allow transferring the control file 
pda(site_id = 'site1', control = control, dir = mydir)
 

## in actual collaboration, account/password for pda server will be assigned, thus:
# pda(site_id = 'site1', control = control, uri = 'https://pda.one', secret='abc123')
## you can also set your environment variables, and no need to specify them in pda:
# Sys.setenv(PDA_USER = 'site1', PDA_SECRET = 'abc123', PDA_URI = 'https://pda.one')
# pda(site_id = 'site1', control = control)


## assume remote site3: enter "1" to allow tranferring your local estimate 
pda(site_id = 'site3', ipdata = LOS_split[[3]], dir=mydir)
 
## assume remote site2: enter "1" to allow tranferring your local estimate  
pda(site_id = 'site2', ipdata = LOS_split[[2]], dir=mydir)
 
## assume lead site1: enter "1" to allow tranferring your local estimate  
## control.json is also automatically updated
pda(site_id = 'site1', ipdata = LOS_split[[1]], dir=mydir)
 
``` 

### Other algorithms

#### Linear model with fixed site-effect

#### Linear model with random site-effect (Linear mixed model)


## Results and Running time




