#include "film_utils.h"
#include <map>
#include <algorithm>

namespace miit::cinema {

void print_film_by_title(const std::vector<Film*>& films, const std::string& title) {
    std::cout << "Search film by title" << std::endl;
    for (size_t i = 0; i < films.size(); i++) {
        if (films[i]->get_title() == title) {
            std::cout << *films[i] << std::endl;
            return;
        }
    }
    std::cout << "Film with title '" << title << "' not found." << std::endl;
}

void print_films_by_genre(const std::vector<Film*>& films, const std::string& genre) {
    std::cout << "Films by genre: " << genre << "-" << std::endl;
    bool found = false;
    for (size_t i = 0; i < films.size(); i++) {
        if (films[i]->get_genre() == genre) {
            std::cout << "- " << films[i]->get_title() << " (" << films[i]->get_year() << ")" << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No films found in genre '" << genre << "-" << std::endl;
    }
}

void print_films_by_director(const std::vector<Film*>& films, const std::string& director) {
    std::cout << "Films by director: " << director << "-" << std::endl;
    bool found = false;
    for (size_t i = 0; i < films.size(); i++) {
        if (films[i]->get_director() == director) {
            std::cout << "- " << films[i]->get_title() << " (" << films[i]->get_year() << ")" << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "No films found by director " << director << "." << std::endl;
    }
}

void print_films_by_actor(const std::vector<Film*>& films, const std::string& actor) {
    std::cout << "Films with actor: " << actor << "" << std::endl;
    bool found = false;
    for (size_t i = 0; i < films.size(); i++) {
        const std::vector<std::string>& actors = films[i]->get_actors();
        for (size_t j = 0; j < actors.size(); j++) {
            if (actors[j] == actor) {
                std::cout << "- " << films[i]->get_title() << " (" << films[i]->get_year() << ")" << std::endl;
                found = true;
                break;
            }
        }
    }
    if (!found) {
        std::cout << "No films found with actor '" << actor << "'." << std::endl;
    }
}

void print_available_media_for_film(Film* film) {
    if (film == nullptr) {
        std::cout << "Film is null." << std::endl;
        return;
    }
    
    std::cout << "Available media for: " << film->get_title() << "-" << std::endl;
    const std::vector<MediaType*>& media = film->get_available_media();
    
    if (media.empty()) {
        std::cout << "No media available for this film." << std::endl;
        return;
    }
    
    for (size_t i = 0; i < media.size(); i++) {
        std::cout << "- " << media[i]->get_format_string() 
                  << " | Price: $" << media[i]->get_price()
                  << " | In stock: " << media[i]->get_stock_quantity() << std::endl;
    }
}

void print_most_sold_films(const std::vector<Sale*>& sales) {
    std::cout << "Most sold films" << std::endl;
    
    if (sales.empty()) {
        std::cout << "No sales data available." << std::endl;
        return;
    }
    
    std::map<std::string, int> film_sales;
    
    for (size_t i = 0; i < sales.size(); i++) {
        if (sales[i]->get_film() != nullptr) {
            std::string title = sales[i]->get_film()->get_title();
            film_sales[title] += sales[i]->get_quantity();
        }
    }
    
    std::vector<std::pair<std::string, int>> sorted_sales(film_sales.begin(), film_sales.end());
    std::sort(sorted_sales.begin(), sorted_sales.end(), 
              [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                  return a.second > b.second;
              });
    
    for (size_t i = 0; i < sorted_sales.size(); i++) {
        std::cout << (i + 1) << ". " << sorted_sales[i].first 
                  << " - " << sorted_sales[i].second << " copies sold" << std::endl;
    }
}

void print_sales_in_period(const std::vector<Sale*>& sales, const std::string& start_date, const std::string& end_date) {
    std::cout << "Sales from " << start_date << " to " << end_date << "-" << std::endl;
    
    int total_quantity = 0;
    double total_amount = 0.0;
    bool found = false;
    
    for (size_t i = 0; i < sales.size(); i++) {
        std::string date = sales[i]->get_date();
        if (date >= start_date && date <= end_date) {
            if (sales[i]->get_film() != nullptr) {
                std::cout << "- " << date << ": " << sales[i]->get_film()->get_title() << " (" << sales[i]->get_media()->get_format_string() << ")" << " x" << sales[i]->get_quantity() << " = $" << sales[i]->get_total_amount() << std::endl;
                total_quantity += sales[i]->get_quantity();
                total_amount += sales[i]->get_total_amount();
                found = true;
            }
        }
    }
    
    if (!found) {
        std::cout << "No sales in this period." << std::endl;
    } else {
        std::cout << "\nTotal quantity sold: " << total_quantity << std::endl;
        std::cout << "Total sales amount: $" << total_amount << std::endl;
    }
}

double calculate_total_sales_amount(const std::vector<Sale*>& sales, const std::string& start_date, const std::string& end_date) {
    double total = 0.0;
    
    for (size_t i = 0; i < sales.size(); i++) {
        std::string date = sales[i]->get_date();
        if (date >= start_date && date <= end_date) {
            total += sales[i]->get_total_amount();
        }
    }
    
    return total;
}

}