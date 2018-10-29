#include <xtensor-r/rarray.hpp>
#include <xtensor-r/rtensor.hpp>
#include <xtensor/xarray.hpp>

#include <Rcpp.h>

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

// [[Rcpp::export]]
int xt_dim(xt::rarray<double> x) {
  size_t d = x.dimension();
  return d;
}

// [[Rcpp::export]]
bool xt_shape_ex() {
  using array_type = xt::xarray<double>;
  using shape_type = array_type::shape_type;
  shape_type shape = {3, 2, 4};
  array_type a(shape);
  size_t d = a.dimension();
  const shape_type& s = a.shape();
  bool res = (d == shape.size()) && (s == shape);
  return res;
}
