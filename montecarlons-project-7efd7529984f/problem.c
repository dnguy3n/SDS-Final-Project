#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#include <math.h>
#include "initial_conditions.h"
#include "quad_grid.h"
#include "rect_grid.h"
#include "tri_grid.h"
#include "def_sample.h"
#include "imp_sample.h"
#include "sys_sample.h"
#include "nv_solver.h"
#define A(i,j) a[(i) + (j)*n]
#define V(i,j) v[(i) + (j)*n]
#define W(i,j) w[(i) + (j)*n]
#define IC(i,j) ic[(i) + (j)*n]
int main(){ 
    //defining constants
    FILE *fout, *fopen();
    int n,i,j,x,y,ic_type,grid_type,tsteps;
    double alpha;
    n=1000;
    x =10;
    y = 20;
    double *ic=malloc(n*n*sizeof(double));
    double *v=malloc(x*x*sizeof(double)); 
    double *w=malloc(x*y*sizeof(double)); 
    printf("works");
    //setting up grid
    //options: quad_grid(), rect_grid(), tri_grid()
    //grid_type takes values 0 (quad), 1 (rect), 2 (tri)
    tsteps=2;
    //alpha is viscosity constant, currently for water
    alpha = 10000.0;
    // y=100; use y only if not using quad
    grid_type = 0;


    //specifying initial conditions
    
    //ic_type takes values 0 (top left), 1 (sparse diagonal), 2 (10% rand)
    ic_type = 0;
    
    initial_conditions(ic,n,ic_type);
   
	//choosing sample type
 
    //options: def_sample(), sys_sample(), int_sample()
    if(grid_type==0){
    //for square
	y=x;    
   	v = quad_grid(n,x);
        for(i=0;i<x*x;i++){
        def_sample(ic,v,x,x,n);
	//sys_sample(ic,v,x,x,n); 
	}
	printf("%f\n",V(0,0));
    nv_solver(v,v, n,x,y,grid_type,tsteps, alpha);
       
    //output matrix & parameters
    fout = fopen("output.dat","w");    
    for(i=0;i<x;i++){
        for(j=0;j<x;j++){
            fprintf(fout,"%.2f ", V(i,j));
        }
        fprintf(fout,"\n");
    }
    fprintf(fout,"%f For viscosity ",alpha); 
    
    fclose(fout);
    
    }
    /*else if(grid_type==1){
    //for rectangles
        w = rect_grid(n,x,y);

	for(i=0;i<x*y;i++){
        def_sample(ic,w,x,y,n);
	//sys_sample(ic,w,x,y,n); 
	}
	printf("%f\n",W(0,0));
   } 
   nv_solver(v,w,n,x,y,grid_type,tsteps, alpha);
   
    //output matrix & parameters
    fout = fopen("output.dat","w");    
    for(i=0;i<x;i++){
        for(j=0;j<y;j++){
   //         fprintf(fout,"%.2f ", W(i,j));
        }
        fprintf(fout,"\n");
    }
    fprintf(fout,"%f For viscosity ",alpha); 
    
    fclose(fout);
    }*/
      

    return 0;
}	


