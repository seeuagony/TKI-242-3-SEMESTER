#include "BluRayFilm.h"
#include <sstream>

namespace miit::cinema
{
    BluRayFilm::BluRayFilm(const std::string& title, const Person& director, const std::string& description, double price, bool is4K, bool hasHDR) : Film(title, director, description, price), is4K(is4K), hasHDR(hasHDR)
    {
    }

    bool BluRayFilm::getIs4K() const
    {
        return is4K;
    }

    bool BluRayFilm::getHasHDR() const
    {
        return hasHDR;
    }

    void BluRayFilm::setIs4K(bool is4K)
    {
        this->is4K = is4K;
    }

    void BluRayFilm::setHasHDR(bool hasHDR)
    {
        this->hasHDR = hasHDR;
    }

    std::string BluRayFilm::getMediaType() const
    {
        return "Blu-ray";
    }

    std::string BluRayFilm::getInfo() const
    {
        std::ostringstream oss;
        oss << Film::getInfo();
        oss << "4K: " << (is4K ? "Да" : "Нет") << "\n";
        oss << "HDR: " << (hasHDR ? "Да" : "Нет") << "\n";
        return oss.str();
    }
}