#include "Film.h"
#include "MediaType.h"

namespace miit::cinema {

Film::Film() : title(""), genre(""), year(0), director(""), description(""), actors(), available_media() {}

Film::Film(const std::string& title, const std::string& genre, int year, const std::string& director, const std::string& description) : title(title), genre(genre), year(year), director(director), description(description), actors(), available_media() {}

Film::Film(const Film& other) : title(other.title), genre(other.genre), year(other.year), director(other.director), description(other.description), actors(other.actors), available_media(other.available_media) {}

Film& Film::operator=(const Film& other) {
    if (this != &other) {
        title = other.title;
        genre = other.genre;
        year = other.year;
        director = other.director;
        description = other.description;
        actors = other.actors;
        available_media = other.available_media;
    }
    return *this;
}

std::string Film::get_title() const {
    return title;
}

std::string Film::get_genre() const {
    return genre;
}

int Film::get_year() const {
    return year;
}

std::string Film::get_director() const {
    return director;
}

std::string Film::get_description() const {
    return description;
}

const std::vector<std::string>& Film::get_actors() const {
    return actors;
}

const std::vector<MediaType*>& Film::get_available_media() const {
    return available_media;
}

void Film::add_actor(const std::string& actor) {
    actors.push_back(actor);
}

void Film::add_media(MediaType* media) {
    if (media == nullptr)
        return;
    for (MediaType* existing_media : available_media) {
        if (existing_media == media)
            return;
    }
    available_media.push_back(media);
}

std::ostream& operator<<(std::ostream& os, const Film& film) {
    os << "Film" << std::endl;
    os << "Title: " << film.title << std::endl;
    os << "Genre: " << film.genre << std::endl;
    os << "Year: " << film.year << std::endl;
    os << "Director: " << film.director << std::endl;
    os << "Description: " << film.description << std::endl;
    
    os << "Actors: ";
    if (film.actors.empty()) {
        os << "no actors listed" << std::endl;
    } else {
        os << std::endl;
        for (size_t i = 0; i < film.actors.size(); ++i) {
            os << "  - " << film.actors[i] << std::endl;
        }
    }
    
    os << "Available media: " << film.available_media.size() << " type(s)" << std::endl;
    
    return os;
}

std::istream& operator>>(std::istream& is, Film& film) {
    std::cout << "Enter title: ";
    std::getline(is, film.title);
    
    std::cout << "Enter genre: ";
    std::getline(is, film.genre);
    
    std::cout << "Enter year: ";
    is >> film.year;
    is.ignore();
    
    std::cout << "Enter director: ";
    std::getline(is, film.director);
    
    std::cout << "Enter description: ";
    std::getline(is, film.description);
    
    film.actors.clear();
    film.available_media.clear();
    
    return is;
}

}