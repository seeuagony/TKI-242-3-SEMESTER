#pragma once
#include <string>
#include <iostream>
#include "Film.h"
#include "MediaType.h"

namespace miit::cinema {

// Forward declarations
class Film;
class MediaType;

/**
 * @brief класс, описывающий продажу фильма
 */
class Sale {
private:
    std::string date;
    Film* film;
    MediaType* media;
    int quantity;

public:
    /**
     * @brief конструктор по умолчанию
     */
    Sale();
    
    /**
     * @brief конструктор с параметрами
     * @param date дата продажи
     * @param film указатель на фильм
     * @param media указатель на носитель
     * @param quantity количество проданных копий
     */
    Sale(const std::string& date, Film* film, MediaType* media, int quantity);
    
    /**
     * @brief конструктор копирования
     * @param other другой объект класса Sale
     */
    Sale(const Sale& other);
    
    /**
     * @brief перегрузка оператора присваивания
     * @param other другой объект класса Sale
     * @return ссылка на текущий объект
     */
    Sale& operator=(const Sale& other);
    
    /**
     * @brief деструктор по умолчанию
     */
    ~Sale() = default;
    
    /**
     * @brief возвращает дату продажи
     * @return дата продажи
     */
    std::string get_date() const;
    
    /**
     * @brief возвращает указатель на фильм
     * @return указатель на объект Film
     */
    Film* get_film() const;
    
    /**
     * @brief возвращает указатель на носитель
     * @return указатель на объект MediaType
     */
    MediaType* get_media() const;
    
    /**
     * @brief возвращает количество проданных копий
     * @return количество копий
     */
    int get_quantity() const;
    
    /**
     * @brief вычисляет общую сумму продажи
     * @return сумма продажи
     */
    double get_total_amount() const;
    
    /**
     * @brief перегрузка оператора вывода
     * @param os ссылка на поток вывода
     * @param sale ссылка на объект класса Sale
     * @return ссылка на итоговый поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Sale& sale);
    
    /**
     * @brief перегрузка оператора ввода
     * @param is ссылка на поток ввода
     * @param sale ссылка на объект класса Sale
     * @return ссылка на итоговый поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Sale& sale);
};

}