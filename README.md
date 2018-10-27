
<!-- README.md is generated from README.Rmd. Please edit that file -->

# xcursion

[![Lifecycle:
experimental](https://img.shields.io/badge/lifecycle-experimental-orange.svg)](https://www.tidyverse.org/lifecycle/#experimental)

`xcursion` is a package that uses the headers from `xtensorrr` to show
off a few examples using `xtensor` and `xtensor-r`.

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
