#pragma once
#include "Film.h"
#include "MediaType.h"
#include "Sale.h"
#include "film_utils.h"
#include <vector>
#include <string>

namespace miit::cinema {

/**
 * @brief перечисление команд для взаимодействия с фильмотекой
 */
enum {
    EXIT = 0,
    ADD_FILM,
    ADD_MEDIA,
    ADD_SALE,
    SEARCH_BY_TITLE,
    SEARCH_BY_GENRE,
    SEARCH_BY_DIRECTOR,
    SEARCH_BY_ACTOR,
    SHOW_MEDIA_FOR_FILM,
    SHOW_FILMS_BY_GENRE,
    SHOW_MOST_SOLD,
    SHOW_SALES_IN_PERIOD
};

/**
 * @brief класс фильмотеки (библиотеки фильмов)
 */
class FilmLibrary {
private:
    std::vector<Film*> films;
    std::vector<MediaType*> media_types;
    std::vector<Sale*> sales;
    
    /**
     * @brief находит фильм по названию
     * @param title название фильма
     * @return указатель на фильм или nullptr
     */
    Film* find_film_by_title(const std::string& title) const;

public:
    /**
     * @brief добавляет фильм в фильмотеку
     * @param title название фильма
     * @param genre жанр
     * @param year год выпуска
     * @param director режиссёр
     * @param description описание
     */
    void add_film(const std::string& title, const std::string& genre, int year, const std::string& director, const std::string& description);
    
    /**
     * @brief добавляет актёра к фильму
     * @param film_title название фильма
     * @param actor имя актёра
     */
    void add_actor_to_film(const std::string& film_title, const std::string& actor);
    
    /**
     * @brief добавляет носитель для фильма
     * @param film_title название фильма
     * @param format тип носителя
     * @param price цена
     * @param stock количество на складе
     */
    void add_media_type(const std::string& film_title, MediaFormat format, 
                        double price, int stock);
    
    /**
     * @brief регистрирует продажу фильма
     * @param date дата продажи
     * @param film_title название фильма
     * @param format тип носителя
     * @param quantity количество
     */
    void register_sale(const std::string& date, const std::string& film_title,
                       MediaFormat format, int quantity);
    
    /**
     * @brief выводит информацию о фильме по названию
     * @param title название фильма
     */
    void print_film_info(const std::string& title);
    
    /**
     * @brief выводит список фильмов по жанру
     * @param genre жанр
     */
    void print_films_by_genre(const std::string& genre);
    
    /**
     * @brief выводит список фильмов по режиссёру
     * @param director режиссёр
     */
    void print_films_by_director(const std::string& director);
    
    /**
     * @brief выводит список фильмов по актёру
     * @param actor актёр
     */
    void print_films_by_actor(const std::string& actor);
    
    /**
     * @brief выводит доступные носители для фильма
     * @param title название фильма
     */
    void print_media_for_film(const std::string& title);
    
    /**
     * @brief выводит список наиболее продаваемых фильмов
     */
    void print_most_sold_films();
    
    /**
     * @brief выводит продажи за период
     * @param start_date начальная дата
     * @param end_date конечная дата
     */
    void print_sales_report(const std::string& start_date, const std::string& end_date);
    
    /**
     * @brief запускает интерактивное меню
     */
    void run_interactive_menu();
    
    /**
     * @brief получить количество фильмов
     * @return количество фильмов
     */
    size_t get_films_count() const;
    
    /**
     * @brief получить количество типов носителей
     * @return количество носителей
     */
    size_t get_media_types_count() const;
    
    /**
     * @brief получить количество продаж
     * @return количество продаж
     */
    size_t get_sales_count() const;
    
    /**
     * @brief получить фильм по индексу
     * @param index индекс
     * @return указатель на фильм
     */
    Film* get_film_by_index(size_t index) const;
    
    /**
     * @brief получить носитель по индексу
     * @param index индекс
     * @return указатель на носитель
     */
    MediaType* get_media_by_index(size_t index) const;
    
    /**
     * @brief получить продажу по индексу
     * @param index индекс
     * @return указатель на продажу
     */
    Sale* get_sale_by_index(size_t index) const;
};

}