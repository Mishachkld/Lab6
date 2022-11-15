#include <iostream>
#include <valarray>
#include <fstream>
#include "Func.hpp"

#define SIZE_ARRAY 101
namespace ms{

void outputMatrix(int **matrix, int &N) {
    std::ofstream file(R"(D:\C++Project\Lab6\output.txt)", std::ios::out);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
//            std::cout << matrix[j][i] << " ";
            file << matrix[j][i]<< " ";
        }
        file << std::endl;
    }
    file.close();
}

void inputMatrix(int **matrix, int &N) {
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

bool isChangeMatrix(int **matrix, int &N) {
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

void sortMatrix(int **matrix, int &N) { // отсортировать по убыванию нормы столбцов (т.е. столбец с наибольшей нормой на 1-ом месте, с менньшей на 2-ом и т.д.)
    int counterNorm[SIZE_ARRAY];
    for (int j = 0; j < N; j++) {
        int norm = 0;
        for (int i = 0; i < N; i++) {
            norm += matrix[j][i] * matrix[j][i];
        }
        counterNorm[j] = norm;
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (counterNorm[i] < counterNorm[j]) {
                std::swap(matrix[i], matrix[j]);
                std::swap(counterNorm[i], counterNorm[j]);

            }
        }
    }

//    return matrix;
}

}

