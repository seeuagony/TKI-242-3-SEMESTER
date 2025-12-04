#pragma once
#include "Generator.h"
#include <random>

namespace miit::algebra {
    /**
    @brief Генератор случайных чисел в заданном диапазоне 
    */
    class RandomGenerator : public Generator {
        private:
        std::uniform_int_distribution<int> distribution; //функция равномерного распределения целый чисел 
        std::mt19937 generator; // намного менее предсказуемый генератор случайных чисел который лучше rand()

        public:
        /**
        @brief Конструктор рандомного генератора
        @param min минимальное значение в диапазоне
        @param max максимальное значение в диапазоне
        */
        RandomGenerator(int min, int max);

        /**
         * @brief Генерирует случайное число в заданном диапазоне
         * @return Случайное число в диапазоне
         */
        int generate() const override;
    };
}