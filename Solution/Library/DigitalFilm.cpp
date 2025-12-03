#include "DigitalFilm.h"
#include <sstream>

namespace miit::cinema
{
    DigitalFilm::DigitalFilm(const std::string& title, const Person& director, const std::string& description, double price, const std::string& platform, int fileSizeMB) : Film(title, director, description, price), platform(platform), fileSizeMB(fileSizeMB)
    {
    }

    std::string DigitalFilm::getPlatform() const
    {
        return platform;
    }

    int DigitalFilm::getFileSizeMB() const
    {
        return fileSizeMB;
    }

    void DigitalFilm::setPlatform(const std::string& platform)
    {
        this->platform = platform;
    }

    void DigitalFilm::setFileSizeMB(int fileSizeMB)
    {
        this->fileSizeMB = fileSizeMB;
    }

    std::string DigitalFilm::getMediaType() const
    {
        return "Digital";
    }

    std::string DigitalFilm::getInfo() const
    {
        std::ostringstream oss;
        oss << Film::getInfo();
        oss << "Платформа: " << platform << "\n";
        oss << "Размер файла: " << fileSizeMB << " МБ\n";
        return oss.str();
    }
}