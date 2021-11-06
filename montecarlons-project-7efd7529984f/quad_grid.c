#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include "quad_grid.h"
#define B(i,j) b[(i) + (j)*n]
double* quad_grid(int n, int x ){
    int i, j;
    double *b=malloc(x*x*sizeof(double));
   //filling quad grid with 0s 
   //x is number of boxes per axis, n/x is box size in coordinates 
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            B(i,j) = 0; 
        }
    }
    return b;
}	


