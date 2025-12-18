#include "MediaType.h"

namespace miit::cinema {

MediaType::MediaType() : format(DVD), price(0.0), stock_quantity(0), film(nullptr) {}

MediaType::MediaType(MediaFormat format, double price, int stock_quantity, Film* film) : format(format), price(price), stock_quantity(stock_quantity), film(film) {
    if (film != nullptr) {
        film->add_media(this);
    }
}

MediaType::MediaType(const MediaType& other) : format(other.format), price(other.price), stock_quantity(other.stock_quantity), film(other.film) {}

MediaType& MediaType::operator=(const MediaType& other) {
    if (this != &other) {
        format = other.format;
        price = other.price;
        stock_quantity = other.stock_quantity;
        film = other.film;
    }
    return *this;
}

MediaFormat MediaType::get_format() const {
    return format;
}

double MediaType::get_price() const {
    return price;
}

int MediaType::get_stock_quantity() const {
    return stock_quantity;
}

Film* MediaType::get_film() const {
    return film;
}

std::string MediaType::get_format_string() const {
    switch (format) {
        case DVD:     return "DVD";
        case BLURAY:  return "Blu-ray";
        case DIGITAL: return "Digital";
        case VHS:     return "VHS";
        default:      return "Unknown";
    }
}

bool MediaType::reduce_stock(int quantity) {
    if (stock_quantity >= quantity) {
        stock_quantity -= quantity;
        return true;
    }
    return false;
}

void MediaType::add_stock(int quantity) {
    stock_quantity += quantity;
}

std::ostream& operator<<(std::ostream& os, const MediaType& media) {
    os << "Media Type: " << media.get_format_string() 
       << ", Price: $" << media.price 
       << ", In Stock: " << media.stock_quantity;
    if (media.film) {
        os << ", Film: " << media.film->get_title();
    }
    return os;
}

std::istream& operator>>(std::istream& is, MediaType& media) {
    int format_choice;
    std::cout << "Enter media format (0=DVD, 1=Blu-ray, 2=Digital, 3=VHS): ";
    is >> format_choice;
    media.format = static_cast<MediaFormat>(format_choice);
    
    std::cout << "Enter price: ";
    is >> media.price;
    
    std::cout << "Enter stock quantity: ";
    is >> media.stock_quantity;
    
    return is;
}

}