#pragma once

#include "Generator.h"
#include <iostream>

namespace miit::algebra
{
    /**
     * @brief Генератор, читающий значения из входного потока
     */
    class IStreamGenerator : public Generator
    {
    private:
        std::istream& in;

    public:
        /**
         * @brief Конструктор с параметром потока
         * @param in Входной поток (по умолчанию std::cin)
         */
        IStreamGenerator(std::istream& in = std::cin);

        /**
         * @brief Читает одно целое число из потока
         * @return Прочитанное число
         */
        int generate() override;
    };
}