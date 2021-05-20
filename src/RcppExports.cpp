// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// rcpp_coxph_logL
double rcpp_coxph_logL(const arma::vec& beta, const arma::vec& time, const arma::vec& event, const arma::mat& z);
RcppExport SEXP _pda_rcpp_coxph_logL(SEXP betaSEXP, SEXP timeSEXP, SEXP eventSEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type time(timeSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type event(eventSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_coxph_logL(beta, time, event, z));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_coxph_logL_gradient
arma::vec rcpp_coxph_logL_gradient(const arma::vec& beta, const arma::vec& time, const arma::vec& event, const arma::mat& z);
RcppExport SEXP _pda_rcpp_coxph_logL_gradient(SEXP betaSEXP, SEXP timeSEXP, SEXP eventSEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type time(timeSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type event(eventSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_coxph_logL_gradient(beta, time, event, z));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_coxph_logL_hessian
arma::vec rcpp_coxph_logL_hessian(const arma::vec& beta, const arma::vec& time, const arma::vec& event, const arma::mat& z);
RcppExport SEXP _pda_rcpp_coxph_logL_hessian(SEXP betaSEXP, SEXP timeSEXP, SEXP eventSEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type time(timeSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type event(eventSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_coxph_logL_hessian(beta, time, event, z));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_coxph_logL_efron
double rcpp_coxph_logL_efron(const arma::vec& beta, const arma::vec& time, const arma::vec& event, const arma::mat& z);
RcppExport SEXP _pda_rcpp_coxph_logL_efron(SEXP betaSEXP, SEXP timeSEXP, SEXP eventSEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type time(timeSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type event(eventSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_coxph_logL_efron(beta, time, event, z));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_coxph_logL_gradient_efron
arma::vec rcpp_coxph_logL_gradient_efron(const arma::vec& beta, const arma::vec& time, const arma::vec& event, const arma::mat& z);
RcppExport SEXP _pda_rcpp_coxph_logL_gradient_efron(SEXP betaSEXP, SEXP timeSEXP, SEXP eventSEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type time(timeSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type event(eventSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_coxph_logL_gradient_efron(beta, time, event, z));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_coxph_logL_gradient_efron_dist
arma::vec rcpp_coxph_logL_gradient_efron_dist(const arma::vec& beta, const arma::vec& ind_machine_, bool& useLocal, const int dj_cutoff, const arma::vec& time, const arma::vec& event, const arma::mat& z);
RcppExport SEXP _pda_rcpp_coxph_logL_gradient_efron_dist(SEXP betaSEXP, SEXP ind_machine_SEXP, SEXP useLocalSEXP, SEXP dj_cutoffSEXP, SEXP timeSEXP, SEXP eventSEXP, SEXP zSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::vec& >::type beta(betaSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type ind_machine_(ind_machine_SEXP);
    Rcpp::traits::input_parameter< bool& >::type useLocal(useLocalSEXP);
    Rcpp::traits::input_parameter< const int >::type dj_cutoff(dj_cutoffSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type time(timeSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type event(eventSEXP);
    Rcpp::traits::input_parameter< const arma::mat& >::type z(zSEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_coxph_logL_gradient_efron_dist(beta, ind_machine_, useLocal, dj_cutoff, time, event, z));
    return rcpp_result_gen;
END_RCPP
}
// rcpp_aggregate
arma::mat rcpp_aggregate(const arma::mat& x, const arma::vec& indices, const bool simplify, const bool cumulative, const bool reversely);
RcppExport SEXP _pda_rcpp_aggregate(SEXP xSEXP, SEXP indicesSEXP, SEXP simplifySEXP, SEXP cumulativeSEXP, SEXP reverselySEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const arma::mat& >::type x(xSEXP);
    Rcpp::traits::input_parameter< const arma::vec& >::type indices(indicesSEXP);
    Rcpp::traits::input_parameter< const bool >::type simplify(simplifySEXP);
    Rcpp::traits::input_parameter< const bool >::type cumulative(cumulativeSEXP);
    Rcpp::traits::input_parameter< const bool >::type reversely(reverselySEXP);
    rcpp_result_gen = Rcpp::wrap(rcpp_aggregate(x, indices, simplify, cumulative, reversely));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_pda_rcpp_coxph_logL", (DL_FUNC) &_pda_rcpp_coxph_logL, 4},
    {"_pda_rcpp_coxph_logL_gradient", (DL_FUNC) &_pda_rcpp_coxph_logL_gradient, 4},
    {"_pda_rcpp_coxph_logL_hessian", (DL_FUNC) &_pda_rcpp_coxph_logL_hessian, 4},
    {"_pda_rcpp_coxph_logL_efron", (DL_FUNC) &_pda_rcpp_coxph_logL_efron, 4},
    {"_pda_rcpp_coxph_logL_gradient_efron", (DL_FUNC) &_pda_rcpp_coxph_logL_gradient_efron, 4},
    {"_pda_rcpp_coxph_logL_gradient_efron_dist", (DL_FUNC) &_pda_rcpp_coxph_logL_gradient_efron_dist, 7},
    {"_pda_rcpp_aggregate", (DL_FUNC) &_pda_rcpp_aggregate, 5},
    {NULL, NULL, 0}
};

RcppExport void R_init_pda(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
