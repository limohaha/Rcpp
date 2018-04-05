## 1. Suitable situations to use Rcpp
R is weak and slow in loop and matrix operations. If the following operations involved in your coding process, you can consider using Rcpp instead of R to speed up your programs.  
* Loop iterations are sequential: later iterations depend on previous iterations;  
* Accessing each elements from a matrix or lists is required;  
* Recurrent function calls with loops;  
* The size of object is dynamically changed via looping;  
* Higher dimensional array must be applied in operation or some advanced data structured is required;
You can install Rcpp by  
```r
install.packages("Rcpp")
```
Programing and compiling in Rstudio and execute in R may faster.
## 2. Basic Usage  
3 steps in use Rcpp:  
1. Writing Rcpp source code in .cpp file  
2. Compiling the code  
3. Execute the function in .R file
### 2.1 Writing Rcpp source code in .cpp file  
Example of Masaki's manual: calculation summation of a vector;
```cpp
//sum.cpp
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double rcpp_sum(NumericVector v){
    double sum = 0;
    for(int i=0; i<v.length(); ++i){
        sum += v[i];
    }
    return(sum);
}
```
How to define your own function and passing object values as argument between functions?  
```cpp
#include<Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
RETURN_TYPE FUNCTION_NAME(ARGMENT_TYPE ARGMENT){

    //do something

    return RETURN_VALUE;
}
```
* `#include<Rcpp.h>`: Enable usage of classes and Rcpp packages;  
* `using namespace Rcpp;`: Optional. Indicating Rcpp function will be used;
* `RETURN_TYPE FUNCTION_NAME(ARGMENT_TYPE ARGMENT){}`: specify function types and arguments;  
* `return RETURN_VALUE`: return the calculated values into R. If you do not have a returned value, (type will be void) and the return code can be omited;  
### 2.2 Compiling the code  
The compiling of code will be executed in R with calling `Rcpp` library, the written Rcpp script must under your current working directory.  
```r
library(Rcpp)
sourceCpp('sum.cpp')
```
### 2.3 Executing the Rcpp function in R
Use the Rcpp compiled function as a R function in console window.  
```r
rcpp_sum(1:10)
```

## Reference:
Masaki, E. (2018). [Rcpp for everyone](https://teuder.github.io/rcpp4everyone_en/)
