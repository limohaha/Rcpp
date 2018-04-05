# Rcpp_Objects
Introduce several different data types will be used in Rcpp programing.  
* Basic Types;  
* Advanced Types;  

## 1. Basic Data Types
The basic data types are provided by R are also available in Rcpp. Using these data types, you can directly access the global variable in R environment. 
Following are the basic data types: `logical` `integer` `numeric` `complex` `character` `Date` `POSIXct`.  
The following are the related data types in R, Rcpp and Cpp for both vectors and matrix.  

| Value    | R Vector  | Rcpp Vector     | Rcpp Matrix     | Rcpp Scalar | Cpp Scalar |
|----------|-----------|-----------------|-----------------|-------------|------------|
| Logical  | logical   | LogicalVector   | LogicalMatrix   | -           | bool       |
| Integer  | integer   | IntegerVector   | IntegerMatrix   | -           | int        |
| Real     | numeric   | NumericVector   | NumericMatrix   | -           | double     |
| Complex  | complex   | ComplexVector   | ComplexMatrix   | Rcomplex    | complex    |
| String   | character | CharacterVector | CharacterMatrix | String      | string     |
| Date     | Date      | DateVector      | -               | Date        | -          |
| Datetime | POSIXct   | DatetimeVector  | -               | Datetime    | time-t     |

Additionally, Rcpp also has data frame, list, S3 class and S4 class as well.  

| R            | Rcpp        |
|--------------|-------------|
| `data.frame` | `DataFrame` |
| list         | List        |
| S3 class     | List        |
| S4 class     | S4          |
## 2. Advanced Types  
The mainly introduced advanced data types here is the high dimensional arrays. A high dimensional array can be allocated by `array(0, c(1,2,3,4))` in R environment. RcppArmadillo can let us have `cube` object with the same properties.
Small Example in the followings about `cube`:  
In R:   
```r
library(Rcpp)
library(RcppArmadillo)
# compiling cpp file
sourceCpp('r_scripts/rcpp/iter_FS.cpp')
haha <- array(0, c(5,6,7))
haha[1,2,3] <- 518
rcpp_test(haha)
```
In cpp separate file:  
```cpp
#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::export]]

double test(arma::cube& X){
  Rcout << "The value is " << X(0,1,2) << std::endl;
  return(X(0,1,2));
}
```
PS: You do not need to include `#include <Rcpp.h>` given `include <RcppArmadillo.h>` exist in your .cpp file.  
