#include <iostream>
#include "../Library/RandomGenerator.h"
#include "../Library/IStreamGenerator.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/ZeroGenerator.h"

int main() {
    std::cout << "=== Тестирование генераторов ===\n\n";
    
    // 1. RandomGenerator
    std::cout << "1. RandomGenerator (10 случайных чисел от 1 до 100):\n";
    miit::algebra::RandomGenerator randomGen(1, 100);
    for (int i = 0; i < 10; i++) {
        std::cout << randomGen.generate() << " ";
    }
    std::cout << "\n\n";
    
    // 2. ConstantGenerator
    std::cout << "2. ConstantGenerator (10 раз число 42):\n";
    miit::algebra::ConstantGenerator constGen(42);
    for (int i = 0; i < 10; i++) {
        std::cout << constGen.generate() << " ";
    }
    std::cout << "\n\n";
    
    // 3. ZeroGenerator
    std::cout << "3. ZeroGenerator (10 нулей):\n";
    miit::algebra::ZeroGenerator zeroGen;
    for (int i = 0; i < 10; i++) {
        std::cout << zeroGen.generate() << " ";
    }
    std::cout << "\n\n";
    
    // 4. IStreamGenerator (раскомментируй, если хочешь протестировать ввод)
    /*
    std::cout << "4. IStreamGenerator (введи 5 чисел через пробел или Enter):\n";
    miit::algebra::IStreamGenerator inputGen;
    for (int i = 0; i < 5; i++) {
        std::cout << "Введённое число: " << inputGen.generate() << "\n";
    }
    */
    
    std::cout << "\n✅ Все генераторы работают!\n";
    
    return 0;
}