
<!-- README.md is generated from README.Rmd. Please edit that file -->

# xcursion

[![Lifecycle:
experimental](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://www.tidyverse.org/lifecycle/#experimental)

`xcursion` is a package that uses the headers from
[`xtensorrr`](https://github.com/DavisVaughan/xtensorrr) to show off a
few examples using `xtensor` and `xtensor-r`.

## Installation

``` r
devtools::install_github("DavisVaughan/xcursion")
```

## Example

``` r
library(xcursion)
```

Just get a 2x2 numeric matrix back from an `xarray<double>`. There is
some dynamic sizing happening here

``` r
two_by_two_rarray()
#>      [,1] [,2] [,3]
#> [1,]    1    2    3
#> [2,]    5    5    5
```

Just get a 2x2 numeric matrix back from an xtensor\<double, 2\> you have
to be more explicit about sizing here

``` r
two_by_two_rtensor()
#>      [,1] [,2] [,3]
#> [1,]    1    2    3
#> [2,]    5    5    5
```

Add 1 to an R object Using xarray means the dimensions are determined
dynamically

``` r
plus_one(c(1, 2))
#> [1] 2 3

plus_one(matrix(c(1, 2)))
#>      [,1]
#> [1,]    2
#> [2,]    3

plus_one(array(1, dim = c(2, 2, 2)))
#> , , 1
#> 
#>      [,1] [,2]
#> [1,]    2    2
#> [2,]    2    2
#> 
#> , , 2
#> 
#>      [,1] [,2]
#> [1,]    2    2
#> [2,]    2    2
```

``` r
# Interestingly, I think ALTREP breaks some of this
plus_one(1:5)
#> [1] 1 1 1 1 1

plus_one(1:5 + 1) # <- this is fine
#> [1] 3 4 5 6 7
```

Broadcastable sum

``` r
vec <- c(1, 2, 3, 4, 5)
m1 <- matrix(vec, ncol = 1)
m2 <- matrix(vec * 2, ncol = 1)

m3 <- cbind(m1, m2)

# Adding two matrices normally
xt_sum(m1, m2)
#>      [,1]
#> [1,]    3
#> [2,]    6
#> [3,]    9
#> [4,]   12
#> [5,]   15

# Colwise broadcast
xt_sum(m1, m3)
#>      [,1] [,2]
#> [1,]    2    3
#> [2,]    4    6
#> [3,]    6    9
#> [4,]    8   12
#> [5,]   10   15

# Outer sum
xt_sum(m1, t(m1))
#>      [,1] [,2] [,3] [,4] [,5]
#> [1,]    2    3    4    5    6
#> [2,]    3    4    5    6    7
#> [3,]    4    5    6    7    8
#> [4,]    5    6    7    8    9
#> [5,]    6    7    8    9   10

# A vector is a 1 row matrix
# so we get the same result as above
xt_sum(m1, vec)
#>      [,1] [,2] [,3] [,4] [,5]
#> [1,]    2    3    4    5    6
#> [2,]    3    4    5    6    7
#> [3,]    4    5    6    7    8
#> [4,]    5    6    7    8    9
#> [5,]    6    7    8    9   10
```
