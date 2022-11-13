#include <iostream>
#include "Func.hpp"


int main() {
    int N;
    N = getN(N); // ввод с клавиатуры (размер матрицы)
    int **matrix = new int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    inputMatrix(matrix, N);  // ввод матрицы с файла
    if (isChangeMatrix(matrix, N))
       matrix =  sortMatrix(matrix, N);

    outputMatrix(matrix, N);


    delete[]matrix;
    return 0;
}
