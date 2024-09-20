// optimized versions of matrix diagonal summing
#include "matvec.h"

// You can write several different versions of your optimized function
// in this file and call one of them in the last function.

int sumdiag_VER1(matrix_t *mat, vector_t *vec) {
  // change struct ptr -> function calls
  matrix_t mat1 = *mat;
  vector_t vec1 = *vec;
  int matc = mat1.cols;
  int matr = mat1.rows;
  int vecl = vec1.len;
  // intitiualize variables
  int maxdiag = matr + matc - 1;
  int c, r, d;

  //check if length and diag make sense
  if(vecl != maxdiag){
    printf("sumdiag_base: bad sizes\n");
    return 1;
  }

  // initialize vector of diagonal sums to 0
  for(d=0; d<vecl; d++){                     
     VSET(vec1, d, 0);
  }

  for(r=0; r < matr; r++){                  // iterate over rows
    for(c=0; c<matc-5; c+=5){               // iterate over cols
      d = c - r + matc - 1;                 // set diagnals
      VSET(vec1, d, MGET(mat1, r, c) + VGET(vec1, d));
      VSET(vec1, d+1, MGET(mat1, r, c+1) + VGET(vec1, d+1)); // change function calls to macros
      VSET(vec1, d+2, MGET(mat1, r, c+2) + VGET(vec1, d+2)); // mget -> MGET
      VSET(vec1, d+3, MGET(mat1, r, c+3) + VGET(vec1, d+3)); // vget -> VGET
      VSET(vec1, d+4, MGET(mat1, r, c+4) + VGET(vec1, d+4)); // vset -> VSET
    }

    // catch loop
    for(; c<matc; c++){ 
      d = c - r + matc - 1;
      VSET(vec1, d, MGET(mat1, r, c) + VGET(vec1, d));
    }
  }
  return 0;
}

int sumdiag_VER2(matrix_t *mat, vector_t *vec) {
  // OPTIMIZED CODE HERE
  return 0;
}

int sumdiag_OPTM(matrix_t *mat, vector_t *vec) {
  // call your preferred version of the function
  return sumdiag_VER1(mat, vec);
}
