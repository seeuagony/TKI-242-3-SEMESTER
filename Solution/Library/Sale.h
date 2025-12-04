#pragma once

#include <ctime>

namespace miit::cinema
{
    /**
     * @brief Класс для представления информации о продаже
     */
    class Sale
    {
    private:
        std::time_t saleDate;
        int quantity;

    public:
        /**
         * @brief Конструктор по умолчанию
         */
        Sale();

        /**
         * @brief Конструктор с параметрами
         * @param saleDate Дата продажи
         * @param quantity Количество проданных единиц
         */
        Sale(std::time_t saleDate, int quantity);

        /**
         * @brief Получить дату продажи
         * @return Дата продажи
         */
        std::time_t getSaleDate() const;

        /**
         * @brief Получить количество проданных единиц
         * @return Количество
         */
        int getQuantity() const;

        /**
         * @brief Установить дату продажи
         * @param saleDate Дата продажи
         */
        void setSaleDate(std::time_t saleDate);

        /**
         * @brief Установить количество проданных единиц
         * @param quantity Количество
         */
        void setQuantity(int quantity);
    };
}