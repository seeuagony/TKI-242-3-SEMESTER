#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief второй пункт задания
     */
    class Task2 : public Exercise
    {
    private:
        int k;

    public:
        /**
         * @brief Конструктор класса Task2
         * @param matrix Ссылка на объект класса Matrix
         * @param gen Ссылка на генератор для заполнения
         * @param k Число для вставки после чётных элементов
         */
        Task2(Matrix<int>& matrix, Generator& gen, int k);

        /**
         * @brief Реализация выполнения второго пункта задания
         */
        void task() override;

    private:
        /**
         * @brief Подсчёт количества чётных элементов
         * @return Количество чётных элементов в массиве
         */
        size_t countEvenElements();

        /**
         * @brief Создание нового массива с вставленными K
         * @return Новый массив
         */
        Matrix<int> insertKAfterEven();
    };
}
