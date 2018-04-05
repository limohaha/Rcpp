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
The mainly introduced advanced data types here is the high dimensional arrays.
