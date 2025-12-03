#include "Person.h"

namespace miit::cinema
{
    Person::Person() : firstName(""), lastName("")
    {
    }

    Person::Person(const std::string& firstName, const std::string& lastName)
        : firstName(firstName), lastName(lastName)
    {
    }

    std::string Person::getFirstName() const
    {
        return firstName;
    }

    std::string Person::getLastName() const
    {
        return lastName;
    }

    std::string Person::getFullName() const
    {
        return firstName + " " + lastName;
    }

    void Person::setFirstName(const std::string& firstName)
    {
        this->firstName = firstName;
    }

    void Person::setLastName(const std::string& lastName)
    {
        this->lastName = lastName;
    }

    bool Person::operator==(const Person& other) const
    {
        return firstName == other.firstName && lastName == other.lastName;
    }

    bool Person::operator!=(const Person& other) const
    {
        return !(*this == other);
    }
}