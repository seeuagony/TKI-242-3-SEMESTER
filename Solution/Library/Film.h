#pragma once

#include "Genre.h"
#include "Person.h"
#include "Sale.h"
#include <string>
#include <vector>

namespace miit::cinema
{
    /**
     * @brief Базовый абстрактный класс для всех типов фильмов
     */
    class Film
    {
    protected:
        std::string title;
        std::vector<Genre> genres;
        Person director;
        std::vector<Person> cast;
        std::string description;
        double price;
        std::vector<Sale> sales;

    public:
        /**
         * @brief Виртуальный деструктор
         */
        virtual ~Film() = default;

        /**
         * @brief Конструктор с параметрами
         * @param title Название фильма
         * @param director Режиссёр
         * @param description Краткое описание
         * @param price Цена
         */
        Film(const std::string& title, const Person& director, const std::string& description, double price);

        /**
         * @brief Получить название фильма
         * @return Название
         */
        std::string getTitle() const;

        /**
         * @brief Получить режиссёра
         * @return Режиссёр
         */
        Person getDirector() const;

        /**
         * @brief Получить описание
         * @return Описание
         */
        std::string getDescription() const;

        /**
         * @brief Получить цену
         * @return Цена
         */
        double getPrice() const;

        /**
         * @brief Получить список жанров
         * @return Вектор жанров
         */
        std::vector<Genre> getGenres() const;

        /**
         * @brief Получить актёрский состав
         * @return Вектор актёров
         */
        std::vector<Person> getCast() const;

        /**
         * @brief Получить список продаж
         * @return Вектор продаж
         */
        std::vector<Sale> getSales() const;

        /**
         * @brief Добавить жанр
         * @param genre Жанр
         */
        void addGenre(const Genre& genre);

        /**
         * @brief Добавить актёра
         * @param actor Актёр
         */
        void addActor(const Person& actor);

        /**
         * @brief Добавить продажу
         * @param sale Информация о продаже
         */
        void addSale(const Sale& sale);

        /**
         * @brief Получить общее количество проданных копий
         * @return Общее количество продаж
         */
        int getTotalSales() const;

        /**
         * @brief Получить общую сумму продаж
         * @return Сумма продаж
         */
        double getTotalRevenue() const;

        /**
         * @brief Проверить, есть ли указанный жанр
         * @param genre Жанр для проверки
         * @return true если жанр присутствует
         */
        bool hasGenre(const Genre& genre) const;

        /**
         * @brief Проверить, есть ли указанный актёр
         * @param actor Актёр для проверки
         * @return true если актёр присутствует
         */
        bool hasActor(const Person& actor) const;

        /**
         * @brief Получить тип носителя (виртуальная функция)
         * @return Строка с типом носителя
         */
        virtual std::string getMediaType() const = 0;

        /**
         * @brief Получить полную информацию о фильме
         * @return Строка с информацией
         */
        virtual std::string getInfo() const;
    };
}