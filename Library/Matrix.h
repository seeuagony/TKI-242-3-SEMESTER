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
        Matrix(Matrix&& other) noexcept; 

        /**
        @brief Деструктор
        */
        ~Matrix();

        /**
         * @brief Копирующее присваивание
         * @param other Массив для копирования
         * @return указатель на текущий объект
         */
        Matrix& operator=(const Matrix& other);

         /**
         * @brief Перемещающее присваивание
         * @param other Временный массив
         * @return указатель на текущий объект
         */
        Matrix& operator=(Matrix&& other) noexcept;

        /**
         * @brief Доступ к элементу массивапо индексу (для изменения)
         * @param index Индекс элемента
         * @return Ссылка на элемент
         */
        T& operator[](size_t index);

         /**
         * @brief Доступ к элементу массива по индексу (только чтение)
         * @param index Индекс элемента
         * @return Константная ссылка на элемент
         */
        const T& operator[](size_t index) const;

        /**
         * @brief Возвращает размер массива
         * @return Количество элементов
         */
        size_t getSize() const;

        /**
         * @brief Проверяет, пустой ли массив?
         * @return true если массив пустой
         */
        bool isEmpty() const;

        /**
         * @brief Заполняет массив значениями из генератора 
         * @param gen Генератор значений
         */
        void fill(Generator& gen);

        /**
         * @brief Заполняет массив значениями из генератора 
         * @param gen Генератор значений
         */
        void fill(Generator&& gen);

        /**
         * @brief Преобразует массив в строку для вывода
         * @return представление массива как строки
         */
        std::string toString() const;

         /**
         * @brief получить доступ к первому элементу массива
         * @return указатель на первый элемент
         */
        T* getData();

        /**
         * @brief получить доступ к данным только для чтения
         * @return константный указатель на первый элемент
         */
        const T* getData() const;
    };

    // ========== РЕАЛИЗАЦИЯ (внутри namespace!) ==========

    template<typename T>
    Matrix<T>::Matrix() 
        : data(nullptr), size(0)
    {
    }

    template<typename T>
    Matrix<T>::Matrix(size_t n) 
        : data(nullptr), size(n)
    {
        if (n == 0) {
            throw std::invalid_argument("Размер массива не может быть 0");
        }
        data = new T[n];
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& other) 
        : data(nullptr), size(other.size)
    {
        if (other.data != nullptr) {
            data = new T[size];
            for (size_t i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
    }

    template<typename T>
    Matrix<T>::Matrix(Matrix&& other) noexcept 
        : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    template<typename T>
    Matrix<T>::~Matrix()
    {
        delete[] data;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(const Matrix& other)
    {
        if (this != &other) {
            delete[] data;
            
            size = other.size;
            
            if (other.data != nullptr) {
                data = new T[size];
                for (size_t i = 0; i < size; i++) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
        }
        return *this;
    }

    template<typename T>
    Matrix<T>& Matrix<T>::operator=(Matrix&& other) noexcept
    {
        if (this != &other) {
            delete[] data;
    
            data = other.data;
            size = other.size;
            
            other.data = nullptr;
            other.size = 0;
        }
        return *this;
    }

    template<typename T>
    T& Matrix<T>::operator[](size_t index)
    {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        return data[index];
    }

    template<typename T>
    const T& Matrix<T>::operator[](size_t index) const
    {
        if (index >= size) {
            throw std::out_of_range("Индекс выходит за границы массива");
        }
        return data[index];
    }

    template<typename T>
    size_t Matrix<T>::getSize() const
    {
        return size;
    }

    template<typename T>
    bool Matrix<T>::isEmpty() const
    {
        return size == 0;
    }

    template<typename T>
    void Matrix<T>::fill(Generator& gen)
    {
        for (size_t i = 0; i < size; i++) {
            data[i] = static_cast<T>(gen.generate());
        }
    }

    template<typename T>
    void Matrix<T>::fill(Generator&& gen)
    {
        for (size_t i = 0; i < size; i++) {
            data[i] = static_cast<T>(gen.generate());
        }
    }

    template<typename T>
    std::string Matrix<T>::toString() const
    {
        if (isEmpty()) {
            return "[]";
        }
        
        std::ostringstream oss;
        oss << "[";
        for (size_t i = 0; i < size; i++) {
            oss << data[i];
            if (i < size - 1) {
                oss << ", ";
            }
        }
        oss << "]";
        return oss.str();
    }

    template<typename T>
    T* Matrix<T>::getData()
    {
        return data;
    }

    template<typename T>
    const T* Matrix<T>::getData() const
    {
        return data;
    }

}