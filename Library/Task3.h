#pragma once

#include "Exercise.h"
#include <cmath>

namespace miit::algebra
{
    /**
     * @brief Пункт 3
     */
    class Task3 : public Exercise
    {
    public:
        /**
         * @brief Конструктор класса Task3
         * @param matrix Ссылка на объект класса Matrix
         * @param gen Ссылка на генератор для заполнения
         */
        Task3(Matrix<int>& matrix, Generator& gen);

        /**
         * @brief Реализация выполнения третьего пункта задания
         */
        void task() override;

    private:
        /**
         * @brief Создание массива M по правилу
         * @return Новый массив M
         */
        Matrix<int> createArrayM();
    };
}