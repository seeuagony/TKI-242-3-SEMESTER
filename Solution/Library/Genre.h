#pragma once

#include <string>

namespace miit::cinema
{
    /**
     * @brief Класс для представления жанра фильма
     */
    class Genre
    {
    private:
        std::string name;

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        Genre();

        /**
         * @brief Конструктор с параметром
         * @param name Название жанра
         */
        explicit Genre(const std::string& name);

        /**
         * @brief Получить название жанра
         * @return Название жанра
         */
        std::string getName() const;

        /**
         * @brief Установить название жанра
         * @param name Название жанра
         */
        void setName(const std::string& name);
        
        /**
         * @brief Оператор сравнения
         * @param other Другой жанр
         * @return true если жанры равны
         */
        bool operator==(const Genre& other) const;

        /**
         * @brief Оператор неравенства
         * @param other Другой жанр
         * @return true если жанры не равны
         */
        bool operator!=(const Genre& other) const;
    };
}