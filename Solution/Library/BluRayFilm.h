#pragma once

#include "Film.h"

namespace miit::cinema
{
    /**
     * @brief Класс для фильмов на Blu-ray носителе
     */
    class BluRayFilm : public Film
    {
    private:
        bool is4K;
        bool hasHDR;

    public:
        /**
         * @brief Конструктор с параметрами
         * @param title Название фильма
         * @param director Режиссёр
         * @param description Краткое описание
         * @param price Цена
         * @param is4K Поддержка 4K разрешения
         * @param hasHDR Поддержка HDR
         */
        BluRayFilm(const std::string& title, const Person& director, const std::string& description, double price, bool is4K, bool hasHDR);

        /**
         * @brief Проверить поддержку 4K
         * @return true если поддерживает 4K
         */
        bool getIs4K() const;

        /**
         * @brief Проверить поддержку HDR
         * @return true если поддерживает HDR
         */
        bool getHasHDR() const;

        /**
         * @brief Установить поддержку 4K
         * @param is4K Поддержка 4K
         */
        void setIs4K(bool is4K);

        /**
         * @brief Установить поддержку HDR
         * @param hasHDR Поддержка HDR
         */
        void setHasHDR(bool hasHDR);

        /**
         * @brief Получить тип носителя
         * @return Строка "Blu-ray"
         */
        std::string getMediaType() const override;

        /**
         * @brief Получить полную информацию о фильме
         * @return Строка с информацией
         */
        std::string getInfo() const override;
    };
}