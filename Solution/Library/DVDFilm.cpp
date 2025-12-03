#include "DVDFilm.h"
#include <sstream>

namespace miit::cinema
{
    DVDFilm::DVDFilm(const std::string& title, const Person& director, const std::string& description, double price, int region) : Film(title, director, description, price), region(region)
    {
    }

    int DVDFilm::getRegion() const
    {
        return region;
    }

    void DVDFilm::setRegion(int region)
    {
        this->region = region;
    }

    std::string DVDFilm::getMediaType() const
    {
        return "DVD";
    }

    std::string DVDFilm::getInfo() const
    {
        std::ostringstream oss;
        oss << Film::getInfo();
        oss << "Регион DVD: " << region << "\n";
        return oss.str();
    }
}