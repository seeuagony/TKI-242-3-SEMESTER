#include "Task3.h"
#include <iostream>

namespace miit::algebra
{
    Task3::Task3(Matrix<int>& matrix, Generator& gen) : Exercise(matrix, gen) 
    {
        std::cout << "Пункт 3" << std::endl;
        matrix.fill(gen);
    }
    Matrix<int> Task3::createArrayM()
    {
        size_t n = matrix.getSize();
        Matrix<int> M(n);
        M[0] = 0;
        M[n - 1] = 0;
        for (size_t i = 1; i < n - 1; i++) {
            if ((i + 1) % 4 == 0) {
                M[i] = 4 * std::abs(matrix[i]);
            } else {
                M[i] = -matrix[i] * static_cast<int>(i + 1);
            }
        }
        return M;
    }

    void Task3::task()
    {
        std::cout << "Было: " << matrix.toString() << std::endl;
        Matrix<int> M = createArrayM();
        std::cout << "После изменения массива по правилу: " << M.toString() << std::endl << std::endl;
    }
}