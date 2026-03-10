//WAP in C to find Boolean Matrix conjunction, disjunction and product.
#include <stdio.h>

#define MAX 10

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter the elements of the matrix (0 for false, 1 for true):\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void booleanConjunction(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] && B[i][j]; // AND operation
        }
    }
}

void booleanDisjunction(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] || B[i][j]; // OR operation
        }
    }
}

void booleanProduct(int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Initialize result
            for (int k = 0; k < colsA; k++) {
                result[i][j] = result[i][j] || (A[i][k] && B[k][j]); // Boolean product operation
            }
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    // Input dimensions
    printf("Enter number of rows and columns for the matrices: ");
    scanf("%d %d", &rows, &cols);

    // Input first matrix
    printf("Matrix A:\n");
    inputMatrix(A, rows, cols);

    // Input second matrix
    printf("Matrix B:\n");
    inputMatrix(B, rows, cols);

    // Boolean Conjunction
    booleanConjunction(A, B, result, rows, cols);
    printf("Boolean Conjunction (A AND B):\n");
    printMatrix(result, rows, cols);

    // Boolean Disjunction
    booleanDisjunction(A, B, result, rows, cols);
    printf("Boolean Disjunction (A OR B):\n");
    printMatrix(result, rows, cols);

    // Boolean Product
    // printf("Matrix B (for product):\n");
    // inputMatrix(B, cols, rows); // Note: B must be transposed for product
    booleanProduct(A, B, result, rows, cols, rows);
    printf("Boolean Product (A * B):\n");
    printMatrix(result, rows, rows);

    return 0;
}
