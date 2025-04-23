const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";
/*
 * This routine performs a dgemv operation
 * Y := A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */

// improving the code based on the comments
// reducing the number of computations it performs for the index calculation

void my_dgemv(int n, double* A, double* x, double* y) {

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