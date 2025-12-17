#include "Sale.h"

namespace miit::cinema {

Sale::Sale() : date(""), film(nullptr), media(nullptr), quantity(0) {}

Sale::Sale(const std::string& date, Film* film, MediaType* media, int quantity) : date(date), film(film), media(media), quantity(quantity) {}

Sale::Sale(const Sale& other) : date(other.date), film(other.film), media(other.media), quantity(other.quantity) {}

Sale& Sale::operator=(const Sale& other) {
    if (this != &other) {
        date = other.date;
        film = other.film;
        media = other.media;
        quantity = other.quantity;
    }
    return *this;
}

std::string Sale::get_date() const {
    return date;
}

Film* Sale::get_film() const {
    return film;
}

MediaType* Sale::get_media() const {
    return media;
}

int Sale::get_quantity() const {
    return quantity;
}

double Sale::get_total_amount() const {
    if (media != nullptr) {
        return media->get_price() * quantity;
    }
    return 0.0;
}

std::ostream& operator<<(std::ostream& os, const Sale& sale) {
    os << "Sales" << std::endl;
    os << "Date: " << sale.date << std::endl;
    
    if (sale.film) {
        os << "Film: " << sale.film->get_title() << std::endl;
    } else {
        os << "Film: N/A" << std::endl;
    }
    
    if (sale.media) {
        os << "Media: " << sale.media->get_format_string() << std::endl;
        os << "Price per unit: $" << sale.media->get_price() << std::endl;
    }
    
    os << "Quantity: " << sale.quantity << std::endl;
    os << "Total amount: $" << sale.get_total_amount() << std::endl;
    
    return os;
}

std::istream& operator>>(std::istream& is, Sale& sale) {
    std::cout << "Enter sale date (YYYY-MM-DD): ";
    is >> sale.date;
    
    std::cout << "Enter quantity: ";
    is >> sale.quantity;
    
    return is;
}

}