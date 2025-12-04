#include "Task2.h"
#include <iostream>

namespace miit::algebra
{
    Task2::Task2(Matrix<int>& matrix, Generator& gen, int k) : Exercise(matrix, gen), k(k) 
    {
        std::cout << "Пункт 2" << std::endl;
        matrix.fill(gen);
    }

    size_t Task2::countEvenElements()
    {
        size_t count = 0;
        for (size_t i = 0; i < matrix.getSize(); i++) {
            if (matrix[i] % 2 == 0) {
                count++;
            }
        }
        return count;
    }

    Matrix<int> Task2::insertKAfterEven()
    {
        size_t evenCount = countEvenElements();
        size_t newSize = matrix.getSize() + evenCount;
        Matrix<int> result(newSize);
        size_t j = 0;
        for (size_t i = 0; i < matrix.getSize(); i++) {
            result[j++] = matrix[i];
            if (matrix[i] % 2 == 0) {
                result[j++] = k;
            }
        }
        
        return result;
    }

    void Task2::task()
    {
        std::cout << "Было: " << matrix.toString() << std::endl;
        std::cout << "K = " << k << std::endl;
        Matrix<int> result = insertKAfterEven();
        std::cout << "После вставки числа К после четных элементов: " << result.toString() << std::endl << std::endl;
    }
}