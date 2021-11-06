#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "sys_sample.h"
#define IC(i,j) ic[(i) + (j)*n]
#define B(k,l) grid[(k) + (l)*x]
void sys_sample(double* ic, double* grid, int x, int n){
//n is size of big matrix, x is dimension for grid

double randomnumber,avg,inc;
int check=0,i=0,j=0,k,l,lim;
lim = n/x;
//initialize random number generator
srand(time(NULL));
for (k=0; k<x; k++){
  for (l=0; l<x; l++){
    randomnumber = rand() % 100; 
    inc = 0.0; 
    for(i; i<n; i+10){
      for(j; j<n; j+10){
	inc = inc + IC(i,j);	
        if(IC(i,j)==randomnumber){
	  B(k,l)=IC(i,j);
	  check = check+1;
	} 
      }  
    }
   // i=lim; j=lim;
    //lim = lim+100;
    if (check < 1){
      B(k,l) = inc/100;
    }
  }
}
}
