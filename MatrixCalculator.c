#include <stdio.h>

#define MAX 1e3  // Maximum size of the matrix

// Function prototypes
void readMatrix(int matrix[MAX][MAX], int n);
void printMatrix(int matrix[MAX][MAX], int n);
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int n);
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int n);
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int n);
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int n);

int main() {
    int n;
    int matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];

    printf("Enter the size of the matrix (n x n, n <= %d): ", MAX);
    scanf("%d", &n);

    printf("Enter elements of first matrix:\n");
    readMatrix(matrix1, n);

    printf("Enter elements of second matrix:\n");
    readMatrix(matrix2, n);

    int choice;
    while (1) {
        printf("\nMatrix Calculator:\n");
        printf("1. Add Matrices\n");
        printf("2. Subtract Matrices\n");
        printf("3. Multiply Matrices\n");
        printf("4. Transpose of First Matrix\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMatrices(matrix1, matrix2, result, n);
                printf("Sum of the matrices:\n");
                printMatrix(result, n);
                break;
            case 2:
                subtractMatrices(matrix1, matrix2, result, n);
                printf("Difference of the matrices:\n");
                printMatrix(result, n);
                break;
            case 3:
                multiplyMatrices(matrix1, matrix2, result, n);
                printf("Product of the matrices:\n");
                printMatrix(result, n);
                break;
            case 4:
                transposeMatrix(matrix1, result, n);
                printf("Transpose of the first matrix:\n");
                printMatrix(result, n);
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Function to read a matrix
void readMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to find the transpose of a matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}
