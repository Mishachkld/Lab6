#include <iostream>
#include "Func.hpp"


    void outputData() {
        std::cout << "cout smth" << std::endl;
    }

    int inputData(int &getNumber) {
        std::cin >> getNumber;
        return getNumber;
    }
