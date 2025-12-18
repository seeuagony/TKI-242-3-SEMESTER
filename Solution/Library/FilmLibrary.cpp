#include "FilmLibrary.h"
#include <iostream>
#include <limits>

namespace miit::cinema {

Film* FilmLibrary::find_film_by_title(const std::string& title) const {
    for (Film* film : films) {
        if (film->get_title() == title) {
            return film;
        }
    }
    return nullptr;
}

void FilmLibrary::add_film(const std::string& title, const std::string& genre, int year,
                           const std::string& director, const std::string& description) {
    Film* film = new Film(title, genre, year, director, description);
    films.push_back(film);
    std::cout << "Film added: " << title << std::endl;
}

void FilmLibrary::add_actor_to_film(const std::string& film_title, const std::string& actor) {
    Film* film = find_film_by_title(film_title);
    if (film) {
        film->add_actor(actor);
        std::cout << "Actor '" << actor << "' added to film '" << film_title << "'" << std::endl;
    } else {
        std::cout << "Film '" << film_title << "' not found!" << std::endl;
    }
}

void FilmLibrary::add_media_type(const std::string& film_title, MediaFormat format,
                                 double price, int stock) {
    Film* film = find_film_by_title(film_title);
    if (film) {
        MediaType* media = new MediaType(format, price, stock, film);
        media_types.push_back(media);
        std::cout << "Media type added for film '" << film_title << "'" << std::endl;
    } else {
        std::cout << "Film '" << film_title << "' not found!" << std::endl;
    }
}

void FilmLibrary::register_sale(const std::string& date, const std::string& film_title,
                                MediaFormat format, int quantity) {
    Film* film = find_film_by_title(film_title);
    if (!film) {
        std::cout << "Film '" << film_title << "' not found!" << std::endl;
        return;
    }
    
    MediaType* selected_media = nullptr;
    const std::vector<MediaType*>& available = film->get_available_media();
    
    for (MediaType* media : available) {
        if (media->get_format() == format) {
            selected_media = media;
            break;
        }
    }
    
    if (!selected_media) {
        std::cout << "Media format not available for this film!" << std::endl;
        return;
    }
    
    if (selected_media->reduce_stock(quantity)) {
        Sale* sale = new Sale(date, film, selected_media, quantity);
        sales.push_back(sale);
        std::cout << "Sale registered: " << quantity << " copies of '"
                  << film_title << "' on " << selected_media->get_format_string() << std::endl;
    } else {
        std::cout << "Not enough stock! Available: " << selected_media->get_stock_quantity() << std::endl;
    }
}

void FilmLibrary::print_film_info(const std::string& title) {
    miit::cinema::print_film_by_title(films, title);
}

void FilmLibrary::print_films_by_genre(const std::string& genre) {
    miit::cinema::print_films_by_genre(films, genre);
}

void FilmLibrary::print_films_by_director(const std::string& director) {
    miit::cinema::print_films_by_director(films, director);
}

void FilmLibrary::print_films_by_actor(const std::string& actor) {
    miit::cinema::print_films_by_actor(films, actor);
}

void FilmLibrary::print_media_for_film(const std::string& title) {
    Film* film = find_film_by_title(title);
    if (film) {
        miit::cinema::print_available_media_for_film(film);
    } else {
        std::cout << "Film '" << title << "' not found!" << std::endl;
    }
}

void FilmLibrary::print_most_sold_films() {
    miit::cinema::print_most_sold_films(sales);
}

void FilmLibrary::print_sales_report(const std::string& start_date, const std::string& end_date) {
    miit::cinema::print_sales_in_period(sales, start_date, end_date);
}

void FilmLibrary::run_interactive_menu() {
    int choice;
    std::string input, input2, input3;
    int int_input;
    double double_input;

    while (true) {
        std::cout << "\n=== Film Library System ===\n";
        std::cout << ADD_FILM << ". Add film\n"
                  << ADD_MEDIA << ". Add media type to film\n"
                  << ADD_SALE << ". Register sale\n"
                  << SEARCH_BY_TITLE << ". Search film by title\n"
                  << SEARCH_BY_GENRE << ". Search films by genre\n"
                  << SEARCH_BY_DIRECTOR << ". Search films by director\n"
                  << SEARCH_BY_ACTOR << ". Search films by actor\n"
                  << SHOW_MEDIA_FOR_FILM << ". Show available media for film\n"
                  << SHOW_FILMS_BY_GENRE << ". Show all films by genre\n"
                  << SHOW_MOST_SOLD << ". Show most sold films\n"
                  << SHOW_SALES_IN_PERIOD << ". Show sales report for period\n"
                  << EXIT << ". Exit\n";
        std::cout << "Choose action: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case ADD_FILM: {
                std::string title, genre, director, description;
                int year;
                
                std::cout << "Enter film title: ";
                std::getline(std::cin, title);
                std::cout << "Enter genre: ";
                std::getline(std::cin, genre);
                std::cout << "Enter year: ";
                std::cin >> year;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter director: ";
                std::getline(std::cin, director);
                std::cout << "Enter description: ";
                std::getline(std::cin, description);
                
                add_film(title, genre, year, director, description);
                
                std::cout << "Add actors? (y/n): ";
                char add_actors;
                std::cin >> add_actors;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (add_actors == 'y' || add_actors == 'Y') {
                    std::string actor;
                    while (true) {
                        std::cout << "Enter actor name (or 'done' to finish): ";
                        std::getline(std::cin, actor);
                        if (actor == "done" || actor == "DONE") break;
                        add_actor_to_film(title, actor);
                    }
                }
                break;
            }
            case ADD_MEDIA: {
                std::string title;
                int format;
                double price;
                int stock;
                
                std::cout << "Enter film title: ";
                std::getline(std::cin, title);
                std::cout << "Enter media format (0=DVD, 1=Blu-ray, 2=Digital, 3=VHS): ";
                std::cin >> format;
                std::cout << "Enter price: ";
                std::cin >> price;
                std::cout << "Enter stock quantity: ";
                std::cin >> stock;
                
                add_media_type(title, static_cast<MediaFormat>(format), price, stock);
                break;
            }
            case ADD_SALE: {
                std::string date, title;
                int format, quantity;
                
                std::cout << "Enter sale date (YYYY-MM-DD): ";
                std::cin >> date;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Enter film title: ";
                std::getline(std::cin, title);
                std::cout << "Enter media format (0=DVD, 1=Blu-ray, 2=Digital, 3=VHS): ";
                std::cin >> format;
                std::cout << "Enter quantity: ";
                std::cin >> quantity;
                
                register_sale(date, title, static_cast<MediaFormat>(format), quantity);
                break;
            }
            case SEARCH_BY_TITLE: {
                std::cout << "Enter film title: ";
                std::getline(std::cin, input);
                print_film_info(input);
                break;
            }
            case SEARCH_BY_GENRE: {
                std::cout << "Enter genre: ";
                std::getline(std::cin, input);
                print_films_by_genre(input);
                break;
            }
            case SEARCH_BY_DIRECTOR: {
                std::cout << "Enter director: ";
                std::getline(std::cin, input);
                print_films_by_director(input);
                break;
            }
            case SEARCH_BY_ACTOR: {
                std::cout << "Enter actor name: ";
                std::getline(std::cin, input);
                print_films_by_actor(input);
                break;
            }
            case SHOW_MEDIA_FOR_FILM: {
                std::cout << "Enter film title: ";
                std::getline(std::cin, input);
                print_media_for_film(input);
                break;
            }
            case SHOW_FILMS_BY_GENRE: {
                std::cout << "Enter genre: ";
                std::getline(std::cin, input);
                print_films_by_genre(input);
                break;
            }
            case SHOW_MOST_SOLD: {
                print_most_sold_films();
                break;
            }
            case SHOW_SALES_IN_PERIOD: {
                std::string start, end;
                std::cout << "Enter start date (YYYY-MM-DD): ";
                std::cin >> start;
                std::cout << "Enter end date (YYYY-MM-DD): ";
                std::cin >> end;
                print_sales_report(start, end);
                break;
            }
            case EXIT:
                std::cout << "Exiting Film Library System.\n";
                return;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }
}

size_t FilmLibrary::get_films_count() const {
    return films.size();
}

size_t FilmLibrary::get_media_types_count() const {
    return media_types.size();
}

size_t FilmLibrary::get_sales_count() const {
    return sales.size();
}

Film* FilmLibrary::get_film_by_index(size_t index) const {
    if (index < films.size()) {
        return films[index];
    }
    return nullptr;
}

MediaType* FilmLibrary::get_media_by_index(size_t index) const {
    if (index < media_types.size()) {
        return media_types[index];
    }
    return nullptr;
}

Sale* FilmLibrary::get_sale_by_index(size_t index) const {
    if (index < sales.size()) {
        return sales[index];
    }
    return nullptr;
}

}