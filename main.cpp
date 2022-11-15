#include <iostream>
#include "Func.hpp"


int main() {
    int N;
    N = ms::getN(N); // ввод с клавиатуры (размер матрицы)
    int **matrix = new int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    ms::inputMatrix(matrix, N);  // ввод матрицы с файла
    if (ms::isChangeMatrix(matrix, N))
        ms::sortMatrix(matrix, N);
    ms::outputMatrix(matrix, N);


    delete[]matrix;
    return 0;
}
