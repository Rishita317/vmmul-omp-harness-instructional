// new file that i created
const char* dgemv_desc = "Basic implementation of matrix-vector multiply.";
/*
 * This routine performs a dgemv operation
 * Y := A * X + Y
 * where A is n-by-n matrix stored in row-major format, and X and Y are n by 1 vectors.
 * On exit, A and X maintain their input values.
 */
void my_dgemv(int n, double* A, double* x, double* y) {

    // go each row of the matrix A
    for (int i = 0; i < n; i++) {
        double temp = 0.0; 

        // Temporary variable to store the dot product
        // Compute the dot product of the i-th row of A with vector x
        for (int j = 0; j < n; j++) {
            temp += A[i * n + j] * x[j];
        }
        // Add the result to the corresponding element of vector y
        // same logic code could be a line shorter by using the following line?
        //y[i]+=A[i*n+j]*x[j];
        y[i] += temp;
    }
}

