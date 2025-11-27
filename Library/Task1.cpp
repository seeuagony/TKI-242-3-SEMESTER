#include "Task1.h"
#include <iostream>

namespace miit::algebra
{
    Task1::Task1(Matrix<int>& matrix, Generator& gen) : Exercise(matrix, gen) 
    {
        std::cout << "Пункт 1" << std::endl << std::endl;
        matrix.fill(gen);
    }

    int Task1::findLastMultipleOfThree()
    {
        for (size_t i = matrix.getSize() - 1; i >= 0; i--) {
            if (matrix[i] != 0 && matrix[i] % 3 == 0) {
                return i;
            }
        }
        return -1;
    }

    void Task1::task()
    {
        std::cout << "Было: " << matrix.toString() << std::endl;

        int index = findLastMultipleOfThree();

        if (index == -1) {
            std::cout << "После замены: " << "Элемент, кратный 3, не найден :(" << std::endl;
            return;
        }
        matrix[index] = 0;
        std::cout << "После замены последнего числа кратного 3-м: " << matrix.toString() << std::endl << std::endl;
    }
}