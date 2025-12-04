#pragma once

#include "Generator.h"

namespace miit::algebra
{
    /**
     * @brief Генератор, возвращающий ноль
     */
    class ZeroGenerator : public Generator
    {
    public:
        /**
         * @brief Конструктор по умолчанию
         */
        ZeroGenerator() = default;

        /**
         * @brief Возвращает ноль
         * @return Всегда 0
         */
        int generate() const override;
    };
}