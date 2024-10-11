#include <stdio.h>
#define SIZE 5 
int main() { //open up the main function
    int m1[SIZE][SIZE] = { //define the first matrix 
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = { //define the second matrix
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };
    int printMatrix(int matrix[SIZE][SIZE]) { //define a function to print the matrix
        for(int i = 0; i < SIZE; i++) { //iterate through to size
            for(int j = 0; j < SIZE; j++) { //iterate through to size
                printf("%d ", matrix[i][j]); //print the value at those array coordinates
            }
            printf("\n"); //print a newline
        } 
        return 0; //return out of function
    }
    int addMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) { //define function to add the matrices
        int newMatrix[SIZE][SIZE]; //create a new matrix to hold the result
        for (int i = 0; i < SIZE; i++) { //iterate through to size
            for (int j = 0; j < SIZE; j++) { //iterate through to size
                newMatrix[i][j] = matrix1[i][j] + matrix2[i][j]; //set the new matrix at ij equal to matrix 1 ij + matrix 2 ij
            }
        }
        printMatrix(newMatrix); //print out the new matrix
        return 0; //return out of function
    } 
    int multiplyMatrices(int matrix1[SIZE][SIZE], int matrix2[SIZE][SIZE]) { //define a function to multiply the matrices
        int newMatrix[SIZE][SIZE]; //create a new matrix to hold the result
        for (int i = 0; i < SIZE; i++) { //iterate through to size
            for (int j = 0; j < SIZE; j++) { //iterate through to size
                newMatrix[i][j] = 0; //set the new matrix value at this coordinate to 0
                for (int k = 0; k < SIZE; k++) { //iterate to size again
                    newMatrix[i][j] += matrix1[i][k] * matrix2[k][j]; //follow the formula for matrix multiplication matrix1[i][k] * matrix2[k][j] summed up
                }
            }
        }
        printMatrix(newMatrix); //print out the new matrix
        return 0; //return out of the function
    } 
    int transposeMatrix(int matrix[SIZE][SIZE]) { //define a function to transpose the matrix
        int newMatrix[SIZE][SIZE]; //define a matrix to hold the result
        for (int i = 0; i < SIZE; i++) { //iterate through to size
            for (int j = 0; j < SIZE; j++) { //iterate through to size
                newMatrix[j][i] = matrix[i][j]; //follow formula for matrix transposition
            }
        }
        printMatrix(newMatrix); //print out the new matrix
    }
    printf("Result of adding matrices m1 and m2 together: \n"); //print out a "header" for adding the matrices
    addMatrices(m1,m2); //call addmatrices
    printf("Result of multiplying matrices m1 and m2 together: \n"); //print out a "header" for multiplying the matrices
    multiplyMatrices(m1,m2); //call multiplymatrices
    printf("Result of transposing m1: \n"); //print out a "header" for transposing matrix 1
    transposeMatrix(m1); //call transposematrix
    printf("Result of transposing m2: \n"); //print out a "header" for transposing matrix 2
    transposeMatrix(m2); //call transposematrix
}
