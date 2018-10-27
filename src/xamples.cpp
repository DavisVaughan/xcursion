#include "xtensor-r/rcontainer.hpp"
#include "xtensor-r/rarray.hpp"
#include "xtensor-r/rtensor.hpp"

#include <Rcpp.h>

// [[Rcpp::plugins(cpp14)]]

//' @export
// [[Rcpp::export]]
xt::rarray<double> two_by_two_rarray() {

  // create a 2x2 matrix (dynamically?)
  auto x = xt::rarray<double>(
    {{1, 2, 3},
     {5, 5, 5}}
  );

  return x;
}

//' @export
// [[Rcpp::export]]
xt::rtensor<double, 2> two_by_two_rtensor() {

  // create a 2x2 matrix (static?)
  auto x = xt::rtensor<double, 2>(
    {{1, 2, 3},
    {5, 5, 5}}
  );

  return x;
}

//' @export
// [[Rcpp::export]]
xt::rarray<double> plus_one(xt::rarray<double> x) {

  xt::rarray<double> x_plus_1 = x + 1;

  return x_plus_1;
}
