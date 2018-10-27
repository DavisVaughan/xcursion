#include "xcursion.h"

#include <Rcpp.h>

// [[Rcpp::plugins(cpp14)]]

//' Create a simple two by two matrix with a rarray
//'
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

//' Create a simple two by two matrix with a rtensor
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

//' Take in an R object, and add 1 to it
//'
//' @param x A numeric R object
//'
//' @export
// [[Rcpp::export]]
xt::rarray<double> plus_one(xt::rarray<double> x) {

  xt::rarray<double> x_plus_1 = x + 1;

  return x_plus_1;
}

//' Broadcast sum
//'
//' @param x,y Numeric vectors, matrices, or arrays
//'
//' @export
// [[Rcpp::export]]
xt::rarray<double> xt_sum(xt::rarray<double> x, xt::rarray<double> y) {
  xt::rarray<double> res = x + y;
  return res;
}
