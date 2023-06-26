#include <stdio.h>

/*
* Structure: Defines a matrix with size numRows x numColumns and with entries pointed to by elements.
*/
struct matrix {
    int numRows;
    int numColumns;
    float **elements;      // 2D array to store the matrix elements
};

/*
* Function: createMatrix
* ----------------------
* Creates a new matrix with the specified number of rows and columns.
*
* rows: Number of rows in the matrix
* columns: Number of columns in the matrix
*
* returns: Pointer to the newly created matrix
*/
struct matrix *createMatrix(int rows, int columns);

/*
* Function: fillMatrix
* --------------------
* Fills the elements of a given matrix by taking input from the user.
*
* inputMatrix: Pointer to the matrix to be filled
* rows: Number of rows in the matrix
* columns: Number of columns in the matrix
*
* returns: Pointer to the filled matrix
*/
struct matrix *fillMatrix(struct matrix *inputMatrix, int rows, int columns);

/*
* Function: printMatrix
* ---------------------
* Prints the elements of a given matrix.
*
* inputMatrix: Pointer to the matrix to be printed
*/
void printMatrix(const struct matrix* inputMatrix);

/*
* Function: multByScalar
* ----------------------
* Multiplies a given matrix by a scalar value.
*
* scalar: Scalar value to multiply the matrix by
* inputMatrix: Pointer to the matrix to be multiplied
*
* returns: Pointer to the resulting matrix after scalar multiplication
*/
struct matrix *multByScalar(float scalar, const struct matrix* inputMatrix);

/*
* Function: multMatrices
* ----------------------
* Multiplies two given matrices and returns the resulting matrix.
*
* matrixA: Pointer to the first matrix
* matrixB: Pointer to the second matrix
*
* returns: Pointer to the resulting matrix after matrix multiplication
*/
struct matrix *multMatrices(const struct matrix *matrixA, const struct matrix *matrixB);

/*
* Function: addMatrices
* ---------------------
* Adds two given matrices and returns the resulting matrix.
*
* matrixA: Pointer to the first matrix
* matrixB: Pointer to the second matrix
*
* returns: Pointer to the resulting matrix after matrix addition
*/
struct matrix *addMatrices(const struct matrix *matrixA, const struct matrix *matrixB);
