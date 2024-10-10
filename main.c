#include <stdio.h>
#define SIZE 5
int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    int printMatrix(int matrix[SIZE][SIZE]) {
        for(int i = 0; i < SIZE; i++) {
            for(int j = 0; j < SIZE; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        } 
        return 0;
    }
    int addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
        int newMatrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
            }
        }
        printMatrix(newMatrix);
        return 0;
    } 
    int multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) {
        int newMatrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newMatrix[i][j] = 0;
                for (int k = 0; k < SIZE; k++) {
                    newMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
        printMatrix(newMatrix);
        return 0;
    } 
    int transposeMatrix(int matrix[SIZE][SIZE]) {
        int newMatrix[SIZE][SIZE];
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                newMatrix[j][i] = matrix[i][j];
            }
        }
        printMatrix(newMatrix);
    }
    printf("Result of adding matrices m1 and m2 together: \n");
    addMatrices(m1,m2);
    printf("Result of multiplying matrices m1 and m2 together: \n");
    multiplyMatrices(m1,m2);
    printf("Result of transposing m1: \n");
    transposeMatrix(m1);
    printf("Result of transposing m2: \n");
    transposeMatrix(m2);
}
