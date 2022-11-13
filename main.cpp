#include <iostream>
#include "Func.hpp"


int main() {
    int N;
    N = getN(N);
    int **matrix = new int *[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    inputMatrix(matrix, N);
    if (isChangeMatrix(matrix, N))
        getStringNorm(matrix, N);
    std::swap(matrix[0], matrix[1]);

    outputMatrix(matrix, N);


    delete[]matrix;
    return 0;
}
