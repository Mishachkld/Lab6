#include <iostream>
#include <valarray>
#include "Func.hpp"

#define SIZE_MATRIX 100


void outputMatrix(int **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void inputMatrix(int **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> matrix[i][j];
        }
    }
}

int getN(int &N) {
    std::cin >> N;
    return N;
}

bool isPrime(int &number) {
    for (int i = 2; i <= sqrt(number); i++)
        if (number % i == 0)
            return false;
    return true;
}

bool isChangeMatrix(int **matrix, int N) {
    long normOfMatrix = 0;
    bool result = false;
    for (int i = 0; i < N; i++) {
        int sumOfTecString = 0;
        bool flag = false;
        for (int j = 0; j < N; j++) {
            sumOfTecString += matrix[i][j];
            if (isPrime(matrix[i][j]))
                flag = true;
        }
        if (flag && (sumOfTecString == 0))
            result = true;
    }
    return result;
}

int getStringNorm(int **matrix, int N) { // отсортировать по убыванию нормы столбцов
    int norm = 0;
    for (int i = 0; i < N; i++) {
        int norm = 0;
        for (int j = 0; j < N; j++) {
            norm += (int)pow(matrix[j][i], 2);

        }

    }

    return norm;
}

int **sortMatrix(int **matrix) { // не уверен


    return matrix;
}


