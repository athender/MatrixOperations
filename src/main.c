#include "matrix-operations.c"

/*
* Variables:
*   origMatrix - pointer to the first matrix input
*   newMatrix - pointer to the second input matrix (for addition)
*   tempMatrix - temporary matrix for operations
*   resultMatrix - matrix with the result of the applied operation
*/

int main(){
    struct matrix *origMatrix, *newMatrix, *tempMatrix, *resultMatrix;
    int rows, columns, choice;
    float scalar;

    // Input matrix
    printf("Enter the number of rows in your matrix: ");
    scanf("%d", &rows);
    printf("Enter the number of columns in your matrix: ");
    scanf("%d", &columns);

    tempMatrix = createMatrix(rows, columns);
    origMatrix = fillMatrix(tempMatrix, rows, columns);
    printf("\n");
    printf("Original matrix: \n");
    printMatrix(origMatrix);

    // Choose operation
    printf("Choose the matrix operation to perform:\n");
    printf("1. Multiply the matrix by a scalar\n");
    printf("2. Add two matrices\n");
    printf("3. Multiply two matrices\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            // Multiply matrix by scalar
            printf("Enter the scalar value: ");
            scanf("%f", &scalar);
            resultMatrix = multByScalar(scalar, origMatrix);
            printf("\nResultant matrix after scalar multiplication: \n");
            printMatrix(resultMatrix);
            break;

        case 2:
            // Add two matrices
            printf("Enter the second matrix:\n");
            newMatrix = fillMatrix(tempMatrix, rows, columns);
            resultMatrix = addMatrices(origMatrix, newMatrix);
            printf("\nResultant matrix after addition: \n");
            printMatrix(resultMatrix);
            break;

        case 3:
            // Multiply two matrices
            printf("Enter the number of columns in the second matrix: ");
            scanf("%d", &columns);
            printf("Enter the second matrix:\n");
            tempMatrix = createMatrix(rows, columns);
            newMatrix = fillMatrix(tempMatrix, rows, columns);
            resultMatrix = multMatrices(origMatrix, newMatrix);
            printf("\nResultant matrix after multiplication: \n");
            printMatrix(resultMatrix);
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    // Free memory
    free(origMatrix->elements);
    free(origMatrix);

    if (choice == 2 || choice == 3) {
        free(newMatrix->elements);
        free(newMatrix);
    }

    if (resultMatrix != NULL) {
        free(resultMatrix->elements);
        free(resultMatrix);
    }

    return 0;
}
