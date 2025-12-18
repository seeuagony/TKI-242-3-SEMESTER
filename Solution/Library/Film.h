#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace miit::cinema {

class MediaType;

/**
 * @brief класс, описывающий фильм
 */
class Film {
private:
    std::string title;
    std::string genre;          
    int year;    
    std::string director;
    std::string description;
    
    std::vector<std::string> actors;
    std::vector<MediaType*> available_media;

public:
    /**
     * @brief конструктор по умолчанию
     */
    Film();
    
    /**
     * @brief конструктор с параметрами
     * @param title название фильма
     * @param genre жанр фильма
     * @param year год выпуска
     * @param director режиссёр
     * @param description краткое содержание
     */
    Film(const std::string& title, const std::string& genre, int year, 
         const std::string& director, const std::string& description);
    
    /**
     * @brief конструктор копирования
     * @param other другой объект класса Film
     */
    Film(const Film& other);
    
    /**
     * @brief перегрузка оператора присваивания
     * @param other другой объект класса Film
     * @return ссылка на текущий объект
     */
    Film& operator=(const Film& other);
    
    /**
     * @brief деструктор по умолчанию
     */
    ~Film() = default;
    
    /**
     * @brief возвращает название фильма
     * @return название фильма
     */
    std::string get_title() const;
    
    /**
     * @brief возвращает жанр фильма
     * @return жанр фильма
     */
    std::string get_genre() const;
    
    /**
     * @brief возвращает год выпуска
     * @return год выпуска
     */
    int get_year() const;
    
    /**
     * @brief возвращает режиссёра
     * @return режиссёр
     */
    std::string get_director() const;
    
    /**
     * @brief возвращает краткое содержание
     * @return описание фильма
     */
    std::string get_description() const;
    
    /**
     * @brief возвращает список актёров
     * @return константная ссылка на вектор актёров
     */
    const std::vector<std::string>& get_actors() const;
    
    /**
     * @brief возвращает список доступных носителей
     * @return константная ссылка на вектор носителей
     */
    const std::vector<MediaType*>& get_available_media() const;
    
    /**
     * @brief добавляет актёра в список исполнителей
     * @param actor имя актёра
     */
    void add_actor(const std::string& actor);
    
    /**
     * @brief добавляет носитель в список доступных носителей
     * @param media указатель на объект MediaType
     */
    void add_media(MediaType* media);
    
    /**
     * @brief перегрузка оператора вывода
     * @param os ссылка на поток вывода
     * @param film ссылка на объект класса Film
     * @return ссылка на итоговый поток вывода
     */
    friend std::ostream& operator<<(std::ostream& os, const Film& film);
    
    /**
     * @brief перегрузка оператора ввода
     * @param is ссылка на поток ввода
     * @param film ссылка на объект класса Film
     * @return ссылка на итоговый поток ввода
     */
    friend std::istream& operator>>(std::istream& is, Film& film);
};

}