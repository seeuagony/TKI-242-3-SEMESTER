#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Film.h"
#include "MediaType.h"
#include "Sale.h"

namespace miit::cinema {

/**
 * @brief выводит информацию о фильме по названию
 * @param films вектор фильмов
 * @param title название фильма
 */
void print_film_by_title(const std::vector<Film*>& films, const std::string& title);

/**
 * @brief выводит список фильмов по жанру
 * @param films вектор фильмов
 * @param genre жанр для поиска
 */
void print_films_by_genre(const std::vector<Film*>& films, const std::string& genre);

/**
 * @brief выводит список фильмов по режиссёру
 * @param films вектор фильмов
 * @param director режиссёр для поиска
 */
void print_films_by_director(const std::vector<Film*>& films, const std::string& director);

/**
 * @brief выводит список фильмов по актёру
 * @param films вектор фильмов
 * @param actor имя актёра для поиска
 */
void print_films_by_actor(const std::vector<Film*>& films, const std::string& actor);

/**
 * @brief выводит список доступных носителей для фильма
 * @param film указатель на фильм
 */
void print_available_media_for_film(Film* film);

/**
 * @brief выводит список наиболее продаваемых фильмов
 * @param sales вектор продаж
 */
void print_most_sold_films(const std::vector<Sale*>& sales);

/**
 * @brief выводит количество проданных фильмов за период
 * @param sales вектор продаж
 * @param start_date начальная дата периода
 * @param end_date конечная дата периода
 */
void print_sales_in_period(const std::vector<Sale*>& sales, const std::string& start_date, const std::string& end_date);

/**
 * @brief вычисляет сумму продаж за период
 * @param sales вектор продаж
 * @param start_date начальная дата периода
 * @param end_date конечная дата периода
 * @return общая сумма продаж
 */
double calculate_total_sales_amount(const std::vector<Sale*>& sales, const std::string& start_date, const std::string& end_date);

}