/* This program can perform the following matrix operations:
- Multiply a scalar by a multiple
- Add two matrices
- Multiply two matrices
*/

#include <stdlib.h>
#include <stdbool.h>
#include "matrix-operations.h"

/*
 * Function: createMatrix
 * ----------------------
 * Creates a matrix with the given number of rows and columns.
 *
 * rows: The number of rows in the matrix.
 * columns: The number of columns in the matrix.
 *
 * returns: A pointer to the newly created matrix.
 */

struct matrix *createMatrix(int rows, int columns) {

    struct matrix *newMatrix = malloc(sizeof(struct matrix));

    if (newMatrix == NULL){
        return NULL;
    }

    newMatrix -> numRows = rows;
    newMatrix -> numColumns = columns;
    newMatrix -> elements = malloc(sizeof(float*) * rows);

    if (newMatrix -> elements == NULL){
        free(newMatrix);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        newMatrix -> elements[i] = malloc(sizeof(float) * columns);
        if (newMatrix -> elements[i] == NULL){
            for (int j = i-1; j >= 0; j--){
                free(newMatrix -> elements[j]);
            }
            free(newMatrix -> elements);
            free(newMatrix);
            return NULL;
        }

        for (int j = 0; j < columns; j++) {
            newMatrix -> elements[i][j] = 0;
        }
    }

    return newMatrix;
}

Here's the updated Code 1 with added comment documentation:

c

/***************************
Code 1
***************************/

/* This program can perform the following matrix operations:
- Multiply a scalar by a multiple
- Add two matrices
- Multiply two matrices

Some useful applications for school. */

#include <stdlib.h>
#include <stdbool.h>
#include "matrix-operations.h"

/*
 * Function: createMatrix
 * ----------------------
 * Creates a matrix with the given number of rows and columns.
 *
 * rows: The number of rows in the matrix.
 * columns: The number of columns in the matrix.
 *
 * returns: A pointer to the newly created matrix.
 */
struct matrix *createMatrix(int rows, int columns) {

    struct matrix *newMatrix = malloc(sizeof(struct matrix));

    if (newMatrix == NULL){
        return NULL;
    }

    newMatrix->numRows = rows;
    newMatrix->numColumns = columns;
    newMatrix->elements = malloc(sizeof(float*) * rows);

    if (newMatrix->elements == NULL){
        free(newMatrix);
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        newMatrix->elements[i] = malloc(sizeof(float) * columns);
        if (newMatrix->elements[i] == NULL){
            for (int j = i-1; j >= 0; j--){
                free(newMatrix->elements[j]);
            }
            free(newMatrix->elements);
            free(newMatrix);
            return NULL;
        }

        for (int j = 0; j < columns; j++) {
            newMatrix->elements[i][j] = 0;
        }
    }

    return newMatrix;
}

/*
 * Function: fillMatrix
 * --------------------
 * Fills a given matrix with elements prompted from the user.
 *
 * inputMatrix: The matrix to be filled.
 * rows: The number of rows in the matrix.
 * columns: The number of columns in the matrix.
 *
 * returns: A pointer to the filled matrix.
 */
struct matrix *fillMatrix(struct matrix *inputMatrix, int rows, int columns) {
    for (int i = 0; i < inputMatrix -> numRows; i++) {
        for (int j = 0; j < inputMatrix -> numColumns; j++) {
            printf("Enter element %d, %d: ", i+1, j+1);
            scanf("%f", &(inputMatrix -> elements[i][j]));
        }
    }
    return inputMatrix;
}

/*
 * Function: printMatrix
 * ---------------------
 * Prints the elements of a matrix.
 *
 * inputMatrix: The matrix to be printed.
 */
void printMatrix(const struct matrix* inputMatrix) {

    for (int i = 0; i < inputMatrix -> numRows; i++) {

        for (int j = 0; j < inputMatrix -> numColumns; j++) {
            printf("%f ", inputMatrix -> elements[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

/*
 * Function: multByScalar
 * ----------------------
 * Multiplies a given matrix by a scalar.
 *
 * scalar: The scalar value to multiply with.
 * inputMatrix: The matrix to be multiplied.
 *
 * returns: A pointer to the resulting matrix.
 */

struct matrix *multByScalar (float scalar, const struct matrix* inputMatrix) {

    struct matrix *newMatrix = createMatrix(inputMatrix -> numRows, inputMatrix -> numColumns);
    for (int i = 0; i < inputMatrix -> numRows; i++) {
        for (int j = 0; j < inputMatrix -> numColumns; j++) {

            newMatrix -> elements[i][j] = scalar * inputMatrix -> elements[i][j];
        }
    }
    return newMatrix;
}

/*
 * Function: multMatrices
 * ----------------------
 * Calculates the matrix product of two matrices.
 *
 * matrixA: The first matrix.
 * matrixB: The second matrix.
 *
 * returns: A pointer to the resulting matrix product.
 */

struct matrix *multMatrices (const struct matrix *matrixA, const struct matrix *matrixB) {

    if (matrixA -> numColumns != matrixB -> numRows){
        printf("Matrices not of correct size.");
        return NULL;
    }

    struct matrix *matrixProduct = createMatrix(matrixA -> numRows, matrixB -> numColumns);

    for (int i = 0; i < matrixProduct -> numRows; i++) {
        for (int j = 0; j < matrixA -> numColumns; j++) {
            for (int k = 0; k < matrixA -> numColumns; k++) {

                matrixProduct -> elements[i][j] += (matrixA -> elements[i][k]) * (matrixB -> elements[k][j]);
            }
        }
    }
    return matrixProduct;
}


/*
 * Function: addMatrices
 * ---------------------
 * Calculates the sum of two matrices.
 *
 * matrixA: The first matrix.
 * matrixB: The second matrix.
 *
 * returns: A pointer to the resulting matrix sum.
 */

struct matrix *addMatrices (const struct matrix *matrixA, const struct matrix *matrixB) {
    if ((matrixA -> numRows != matrixB -> numRows) || (matrixA -> numColumns != matrixB -> numColumns)){
        printf("Matrices not of correct size.");
        return NULL;
    }

    struct matrix *matrixSum = createMatrix (matrixA -> numRows, matrixB -> numColumns);

    for (int i = 0; i < matrixSum -> numRows; i++) {
        for (int j = 0; j < matrixSum -> numColumns; j++) {
            matrixSum -> elements[i][j] = (matrixA -> elements[i][j]) + (matrixB -> elements[i][j]);
        }
    }

    return matrixSum;
}
