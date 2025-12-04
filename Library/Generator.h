#pragma once

namespace miit::algebra {
    /**
    @brief Класс для генерации различных значений
    */
    class Generator {
        public:
        /**
        @brief Виртуальный деструктор
        */
        virtual ~Generator() = default;

        /**
        @brief Виртуальная функция генерации значений
        */
        virtual int generate() const = 0;
    };
}