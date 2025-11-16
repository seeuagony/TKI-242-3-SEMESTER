#include <iostream>
#include "../Library/Matrix.h"
#include "../Library/RandomGenerator.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/IStreamGenerator.h"
#include "../Library/ZeroGenerator.h"
#include "../Library/Task1.h"
#include "../Library/Task2.h"
#include "../Library/Task3.h"

using namespace miit::algebra;

int main() {
    std::cout << "Введите размер массива: ";
    size_t n;
    std::cin >> n;
    if (n == 0) {
        std::cerr << "Размер массива должен быть больше 0\n";
        return 1;
    }

    std::cout << "\nВыберите способ заполнения массива:\n";
    std::cout << "  1 - Случайными числами\n";
    std::cout << "  2 - Вручную (ввод с клавиатуры)\n";
    std::cout << "  3 - Константой (одно и то же число)\n";
    std::cout << "  4 - Нулями\n";
    std::cout << "Ваш выбор: ";
    
    int choice;
    std::cin >> choice;

    Generator* gen = nullptr;
    
    switch (choice) {
        case 1: {
            std::cout << "\nВведите минимальное значение: ";
            int min;
            std::cin >> min;
            std::cout << "Введите максимальное значение: ";
            int max;
            std::cin >> max;
            
            if (min > max) {
                std::cerr << "Минимум не может быть больше максимума!\n";
                return 1;
            }
            
            gen = new RandomGenerator(min, max);
            break;
        }
        case 2: {
            std::cout << "\nВы выбрали ввод вручную.\n";
            std::cout << "При заполнении массива введите " << n << " чисел.\n";
            gen = new IStreamGenerator(std::cin);
            break;
        }
        case 3: {
            std::cout << "\nВведите константу для заполнения: ";
            int constant;
            std::cin >> constant;
            gen = new ConstantGenerator(constant);
            break;
        }
        case 4: {
            std::cout << "\nМассив будет заполнен нулями.\n";
            gen = new ZeroGenerator();
            break;
        }
        default:
            std::cerr << "Неверный выбор\n";
            return 1;
    }
    std::cout << "\n";

    std::cout << "Задача 1: Замена последнего элемента, кратного 3\n";
    {
        Matrix<int> arr1(n);
        Task1 task1(arr1, *gen);
        task1.task();
    }
    
    std::cout << "Задача 2: Вставка K после всех чётных элементов\n";
    {
        std::cout << "Введите число K для вставки после чётных элементов: ";
        int k;
        std::cin >> k;
        std::cout << "\n";
        
        Matrix<int> arr2(n);
        Task2 task2(arr2, *gen, k);
        task2.task();
    }

    std::cout << "Задача 3: Формирование массива M по правилу\n";
    {
        Matrix<int> arr3(n);
        Task3 task3(arr3, *gen);
        task3.task();
    }
    
    delete gen;   
    return 0;
}