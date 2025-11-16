#pragma once

#include "Exercise.h"

namespace miit::algebra
{
    /**
     * @brief первый пункт задания
     */
    class Task1 : public Exercise
    {
    public:
        /**
         * @brief Конструктор класса Task1
         * @param matrix Ссылка на объект класса Matrix
         * @param gen Ссылка на генератор для заполнения
         */
        Task1(Matrix<int>& matrix, Generator& gen);

        /**
         * @brief Реализация выполнения первого пункта задания
         */
        void task() override;

    private:
        /**
         * @brief Поиск индекса последнего элемента, кратного 3
         * @return Индекс найденного элемента или -1, если не найден
         */
        int findLastMultipleOfThree();
    };
}
