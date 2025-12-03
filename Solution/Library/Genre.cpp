#include "Genre.h"

namespace miit::cinema
{
    Genre::Genre() : name("")
    {
    }

    Genre::Genre(const std::string& name) : name(name)
    {
    }

    std::string Genre::getName() const
    {
        return name;
    }

    void Genre::setName(const std::string& name)
    {
        this->name = name;
    }

    bool Genre::operator==(const Genre& other) const
    {
        return name == other.name;
    }

    bool Genre::operator!=(const Genre& other) const
    {
        return !(*this == other);
    }
}