# Rcpp_matrix_operation
## 1. How to print a single row/column in Rcpp?
You cannot send rows of the matrix to `Rcpp::cout` in Rcpp, but you can print the matrix or the row via R function `Rf_PrintValue(mat_name)`. The followings are three small functions for printing whole matrix (`print_mat`) and print a single row/column  (`print_row` and `print_col`) with its index.  
```cpp
void print_mat(NumericMatrix& Mat) {
  int nbLig = Mat.nrow(), nbCol = Mat.ncol();
  //int i, j;
  for (i = 0; i < nbLig; i++) {
    for (j = 0; j < nbCol; j++)
      Rprintf("%f ", Mat(i,j));
    Rprintf("\n");
  }
}
void print_row(NumericMatrix& Mat, int rowid){
  int nbCol = Mat.ncol();
  for (j=0; j < nbCol; j++){
    Rprintf("%f", Mat(rowid,j));
  }
  Rprintf("\n");
}
void print_col(NumericMatrix& Mat, int colid){
  int nbRow = Mat.nrow();
  for (i=0; i < nbRow; i++){
    Rprintf("%f", Mat(i,colid));
  }
  Rprintf("\n");
}
```
Notes:  
* Do not forget declare the global index variables at the beginning of scripts;
* You can compile several functions in one .cpp file, but you need to add `//[[Rcpp::export]]` at the beginning of each function;

## 2. Linear Algebra by [RcppArmadillo](https://cran.r-project.org/web/packages/RcppArmadillo/index.html)  
[Link](https://github.com/petewerner/misc/wiki/RcppArmadillo-cheatsheet)
