#pragma once

#include "Film.h"

namespace miit::cinema
{
    /**
     * @brief Класс для цифровых фильмов
     */
    class DigitalFilm : public Film
    {
    private:
        std::string platform;
        int fileSizeMB;

    public:
        /**
         * @brief Конструктор с параметрами
         * @param title Название фильма
         * @param director Режиссёр
         * @param description Краткое описание
         * @param price Цена
         * @param platform Платформа распространения
         * @param fileSizeMB Размер файла в МБ
         */
        DigitalFilm(const std::string& title, const Person& director, const std::string& description, double price, const std::string& platform, int fileSizeMB);

        /**
         * @brief Получить платформу
         * @return Название платформы
         */
        std::string getPlatform() const;

        /**
         * @brief Получить размер файла
         * @return Размер в МБ
         */
        int getFileSizeMB() const;

        /**
         * @brief Установить платформу
         * @param platform Название платформы
         */
        void setPlatform(const std::string& platform);

        /**
         * @brief Установить размер файла
         * @param fileSizeMB Размер в МБ
         */
        void setFileSizeMB(int fileSizeMB);

        /**
         * @brief Получить тип носителя
         * @return Строка "Digital"
         */
        std::string getMediaType() const override;

        /**
         * @brief Получить полную информацию о фильме
         * @return Строка с информацией
         */
        std::string getInfo() const override;
    };
}