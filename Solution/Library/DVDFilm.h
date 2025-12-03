#pragma once

#include "Film.h"

namespace miit::cinema
{
    /**
     * @brief Класс для фильмов на DVD носителе
     */
    class DVDFilm : public Film
    {
    private:
        int region;

    public:
        /**
         * @brief Конструктор с параметрами
         * @param title Название фильма
         * @param director Режиссёр
         * @param description Краткое описание
         * @param price Цена
         * @param region Регион DVD (0-8)
         */
        DVDFilm(const std::string& title, const Person& director, const std::string& description, double price, int region);

        /**
         * @brief Получить регион DVD
         * @return Код региона
         */
        int getRegion() const;

        /**
         * @brief Установить регион DVD
         * @param region Код региона
         */
        void setRegion(int region);

        /**
         * @brief Получить тип носителя
         * @return Строка "DVD"
         */
        std::string getMediaType() const override;

        /**
         * @brief Получить полную информацию о фильме
         * @return Строка с информацией
         */
        std::string getInfo() const override;
    };
}