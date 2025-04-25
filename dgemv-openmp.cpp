#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

const char* dgemv_desc = "OpenMP dgemv.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

// void my_dgemv(int n, double* A, double* x, double* y) {

//    #pragma omp parallel
//    {
//       int nthreads = omp_get_num_threads();
//       int thread_id = omp_get_thread_num();
//       printf("my_dgemv(): Hello world: thread %d of %d checking in. \n", thread_id, nthreads);
//       printf("my_dgemv(): For actual timing runs, please comment out these printf() and omp_get_*() statements. \n");
//    }


void my_dgemv(int n, double* A, double* x, double* y) {

    // splits the for loop automatically 
    #pragma omp parallel for 

    // Iterate over each row of the matrix A
   for (int i = 0; i < n; i++) {
        double temp = 0.0; 

        // Precompute the row offset to avoid redundant calculations
        int Row_Offset = i * n;

        // Compute the dot product of the i-th row of A with vector x
        for (int j = 0; j < n; j++) {
            temp += A[Row_Offset + j] * x[j];
        }

        // Add the result to the corresponding element of vector y
        y[i] += temp;
   }
}

   // TODO: insert your dgemv code here. you may need to create additional parallel regions,
   // and you will want to comment out the above parallel code block that prints out
   // nthreads and thread_id so as to not taint your timings



