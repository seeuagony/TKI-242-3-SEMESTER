#include "Film.h"
#include <sstream>
#include <algorithm>

namespace miit::cinema
{
    Film::Film(const std::string& title, const Person& director, const std::string& description, double price) : title(title), director(director), description(description), price(price)
    {
    }

    std::string Film::getTitle() const
    {
        return title;
    }

    Person Film::getDirector() const
    {
        return director;
    }

    std::string Film::getDescription() const
    {
        return description;
    }

    double Film::getPrice() const
    {
        return price;
    }

    std::vector<Genre> Film::getGenres() const
    {
        return genres;
    }

    std::vector<Person> Film::getCast() const
    {
        return cast;
    }

    std::vector<Sale> Film::getSales() const
    {
        return sales;
    }

    void Film::addGenre(const Genre& genre)
    {
        genres.push_back(genre);
    }

    void Film::addActor(const Person& actor)
    {
        cast.push_back(actor);
    }

    void Film::addSale(const Sale& sale)
    {
        sales.push_back(sale);
    }

    int Film::getTotalSales() const
    {
        int total = 0;
        for (const auto& sale : sales) {
            total += sale.getQuantity();
        }
        return total;
    }

    double Film::getTotalRevenue() const
    {
        return getTotalSales() * price;
    }

    bool Film::hasGenre(const Genre& genre) const
    {
        return std::find(genres.begin(), genres.end(), genre) != genres.end();
    }

    bool Film::hasActor(const Person& actor) const
    {
        return std::find(cast.begin(), cast.end(), actor) != cast.end();
    }

    std::string Film::getInfo() const
    {
        std::ostringstream oss;
        oss << "Название: " << title << "\n";
        oss << "Тип носителя: " << getMediaType() << "\n";
        oss << "Режиссёр: " << director.getFullName() << "\n";
        
        oss << "Жанры: ";
        for (size_t i = 0; i < genres.size(); i++) {
            oss << genres[i].getName();
            if (i < genres.size() - 1) {
                oss << ", ";
            }
        }
        oss << "\n";
        
        oss << "Актёры: ";
        for (size_t i = 0; i < cast.size(); i++) {
            oss << cast[i].getFullName();
            if (i < cast.size() - 1) {
                oss << ", ";
            }
        }
        oss << "\n";
        
        oss << "Описание: " << description << "\n";
        oss << "Цена: " << price << " руб.\n";
        oss << "Продано копий: " << getTotalSales() << "\n";
        
        return oss.str();
    }
}