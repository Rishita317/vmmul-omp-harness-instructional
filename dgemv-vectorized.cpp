const char* dgemv_desc = "Vectorized implementation of matrix-vector multiply.";

/*
 * This routine performs a dgemv operation
 * Y :=  A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

// TODO: You may need to tweak your basic VMM code so that it actually is vectorizable by the compiler. 
//Check the compiler vectorization report (report.txt) to look for evidence that the code vectorized or not. 

void my_dgemv(int n, double* A, double* x, double* y) {
   // insert your code here: implementation of vectorized vector-matrix multiply
    // go each row of the matrix A
    for (int i = 0; i < n; i++) {
        double temp = 0.0; 

        // Precompute the row offset to avoid redundant calculations
        int Row_Offset = i * n; 

        // Temporary variable to store the dot product
        // Compute the dot product of the i-th row of A with vector x

        #pragma omp simd reduction(+:temp)
        
        for (int j = 0; j < n; j++) {
            temp += A[Row_Offset + j] * x[j];
        }

        y[i] += temp;
    }
}

