#pragma once

#include <string>

namespace miit::cinema
{
    /**
     * @brief Класс для представления человека (актёр, режиссёр)
     */
    class Person
    {
    private:
        std::string firstName;
        std::string lastName;

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        Person();

        /**
         * @brief Конструктор с параметрами
         * @param firstName Имя
         * @param lastName Фамилия
         */
        Person(const std::string& firstName, const std::string& lastName);

        /**
         * @brief Получить имя
         * @return Имя
         */
        std::string getFirstName() const;

        /**
         * @brief Получить фамилию
         * @return Фамилия
         */
        std::string getLastName() const;

        /**
         * @brief Получить полное имя
         * @return Полное имя (Имя Фамилия)
         */
        std::string getFullName() const;

        /**
         * @brief Установить имя
         * @param firstName Имя
         */
        void setFirstName(const std::string& firstName);

        /**
         * @brief Установить фамилию
         * @param lastName Фамилия
         */
        void setLastName(const std::string& lastName);

        /**
         * @brief Оператор сравнения
         * @param other Другой человек
         * @return true если люди равны
         */
        bool operator==(const Person& other) const;

        /**
         * @brief Оператор неравенства
         * @param other Другой человек
         * @return true если люди не равны
         */
        bool operator!=(const Person& other) const;
    };
}