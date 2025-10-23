#pragma once

#include "Generator.h"
#include <string>
#include <sstream>
#include <stdexcept>

namespace miit::algebra {
    /**
    @brief Класс динамического массива шаблон 
    @tparam T тип элемента массива
    */
    template<typename T>
    class Matrix {
        private:
        T* data;
        size_t size;

        public:
        /**
        @brief  конструктор по умолчанию
        */
        Matrix();

        /**
        @brief Конструктор с параметрами размера 
        */
        explicit Matrix(size_t n);

        /**
        @brief Копирующий конструктор 
        */
        Matrix(const Matrix& other);

        /**
        @brief Переносящий конструктор 
        */
        Matrix(const Matrix&& other) noexcept;

        /**
        @brief Деструктор
        */
        ~Matrix();
    }
}