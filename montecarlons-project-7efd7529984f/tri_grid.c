#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include "tri_grid.h"
#define A(i,j) a[(i) + (j)*n]
#define B(i,j) b[(i) + (j)*n]
double* tri_grid(int n, int x){
//making quad grid
    int i, j;
    double *b=malloc((2*x)*x*sizeof(double));
   //filling quad grid with 0s 
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            B(i,j) = 0; 
        }
    }

//performing shear mapping

//splitting rhombi

    return b;
}	


