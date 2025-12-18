#pragma once
#include <string>
#include <iostream>
#include "Film.h"

namespace miit::cinema {

class Film;

/**
 * @brief перечисление типов носителей
 */
enum MediaFormat {
    DVD,
    BLURAY,
    DIGITAL,
    VHS
};

/**
 * @brief класс, описывающий носитель фильма
 */
class MediaType {
private:
    MediaFormat format; 
    double price;
    int stock_quantity;
    Film* film; 

public:
    /**
     * @brief конструктор по умолчанию
     */
    MediaType();
    
    /**
     * @brief конструктор с параметрами
     * @param format тип носителя
     * @param price цена
     * @param stock_quantity количество на складе
     * @param film указатель на фильм
     */
    MediaType(MediaFormat format, double price, int stock_quantity, Film* film);
    
    /**
     * @brief конструктор копирования
     * @param other другой объект класса MediaType
     */
    MediaType(const MediaType& other);
    
    /**
     * @brief перегрузка оператора присваивания
     * @param other другой объект класса MediaType
     * @return ссылка на текущий объект
     */
    MediaType& operator=(const MediaType& other);
    
    /**
     * @brief деструктор по умолчанию
     */
    ~MediaType() = default;
    
    /**
     * @brief возвращает тип носителя
     * @return тип носителя
     */
    MediaFormat get_format() const;
    
    /**
     * @brief возвращает цену
     * @return цена носителя
     */
    double get_price() const;
    
    /**
     * @brief возвращает количество на складе
     * @return количество на складе
     */
    int get_stock_quantity() const;
    
    /**
     * @brief возвращает указатель на фильм
     * @return указатель на объект Film
     */
    Film* get_film() const;
    
    /**
     * @brief возвращает строковое представление типа носителя
     * @return название типа носителя
     */
    std::string get_format_string() const;
    
    /**
     * @brief уменьшает количество на складе при продаже
     * @param quantity количество проданных копий
     * @return true если операция успешна, false если недостаточно товара
     */
    bool reduce_stock(int quantity);
    
    /**
     * @brief увеличивает количество на складе
     * @param quantity количество добавленных копий
     */
    void add_stock(int quantity);
    
    /**
     * @brief перегрузка оператора вывода
     * @param os ссылка на поток вывода
     * @param media ссылка на объект класса MediaType
     * @return ссылка на итоговый поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const MediaType& media);
    
    /**
     * @brief перегрузка оператора ввода
     * @param is ссылка на поток ввода
     * @param media ссылка на объект класса MediaType
     * @return ссылка на итоговый поток ввода
     */
    friend std::istream& operator>>(std::istream& is, MediaType& media);
};

}