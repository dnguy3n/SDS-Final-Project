#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include "rect_grid.h"
#define B(i,j) b[(i) + (j)*n]
double* rect_grid(int n, int x, int y ){
    int i, j;
    double *b=malloc(y*x*sizeof(double));
   //filling rect grid with 0s 
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
            B(i,j) = 0; 
        }
    }
    return b;
}	


