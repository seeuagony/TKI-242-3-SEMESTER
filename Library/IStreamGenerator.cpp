#include "IStreamGenerator.h"

namespace miit::algebra
{
    IStreamGenerator::IStreamGenerator(std::istream& in)
        : in{in}
    {
        // Тело конструктора пустое - всё уже инициализировано
    }

    // Реализация метода generate()
    int IStreamGenerator::generate()
    {
        int value = 0;
        in >> value;
        
        return value;
    }
}