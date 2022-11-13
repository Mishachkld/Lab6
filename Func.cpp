#include <iostream>
#include <valarray>
#include <fstream>
#include "Func.hpp"

#define SIZE_MATRIX 100


void outputMatrix(int **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << matrix[j][i] << " ";
        }
        std::cout << std::endl;
    }
}

void inputMatrix(int **matrix, int N) {
    std::ifstream file(R"(D:\C++Project\Lab6\input.txt)", std::ios::in);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            file >> matrix[j][i];
//            std::cin >> matrix[j][i];
        }
    }
    file.close();
}

int getN(int &N) {
//    std::ifstream file(R"(D:\C++Project\Lab6\input.txt)", std::ios::in);
//    file >> N;
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
    bool result = false;
    for (int i = 0; i < N; i++) {
        int sumOfTecString = 0;
        bool flag = false;
        for (int j = 0; j < N; j++) {
            sumOfTecString += matrix[j][i];
            if (isPrime(matrix[j][i]))
                flag = true;
        }
        if (flag && (sumOfTecString == 0))
            return true;
    }
    return result;
}

int **sortMatrix(int **matrix, int N) { // отсортировать по убыванию нормы столбцов
    int counterNorm[N];
    for (int j = 0; j < N; j++) {
        int norm = 0;
        for (int i = 0; i < N; i++) {
            norm += matrix[j][i] * matrix[j][i];

//            std::cout << matrix[j][i] << " ";
        }
        counterNorm[j] = norm;
//        std::cout << counterNorm[j] << "\n";
    }

    for (int i = 0; i < N; i++) {

        for (int j = i + 1; j < N; j++) {
            std::cout << counterNorm[i] << " "<< counterNorm[j]<< "\n";
            if (counterNorm[i] < counterNorm[j]) {
                std::swap(matrix[i], matrix[j]);
                std::swap(counterNorm[i], counterNorm[j]);

            }
            outputMatrix(matrix, N);
            std::cout << "\n";
        }
    }

    return matrix;
}



