// [[Rcpp::depends(RcppArmadillo)]]
#include <RcppArmadillo.h>

using namespace Rcpp;
using namespace arma;


// [[Rcpp::export]]
void toysub(arma::mat& A_mem, arma::mat& B_mem, arma::mat& C_mem, int numbrow, int numbcol){

  arma::mat AA(A_mem.memptr(), numbrow, numbcol, false);
  arma::mat BB(B_mem.memptr(), numbrow, numbcol, false);
  arma::mat CC(C_mem.memptr(), numbrow, numbcol, false);

  int k,j;
  for(k=0;k<numbrow;k++){
    for(j=0;j<numbrow;j++){
      CC(k,j) = AA(k,j) + BB(k,j);
    }
  }
}

// [[Rcpp::export]]
void toy(arma::mat A, arma::mat B){

  int numbrow = A.n_rows;
  int numbcol = A.n_cols;

  arma::mat C(numbrow, numbcol, fill::zeros);

  // double* A_mem = A.memptr();
  // double* B_mem = B.memptr();
  // double* C_mem = C.memptr();

  toysub(A, B, C, numbrow, numbcol);

  A.print();
  B.print();
  C.print();
}
