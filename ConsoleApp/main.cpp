#include <iostream>
#include "../Library/Matrix.h"
#include "../Library/RandomGenerator.h"
#include "../Library/ConstantGenerator.h"
#include "../Library/ZeroGenerator.h"

using namespace miit::algebra;

int main() {
    Matrix<int> arr7(7);
    arr7.fill(ConstantGenerator(7));
    std::cout << "До перемещения: " << arr7.toString() << "\n";
    Matrix<int> arr8 = std::move(arr7);
    std::cout << "После перемещения:\n";
    std::cout << "  arr7: " << arr7.toString() << " (пустой)\n";
    std::cout << "  arr8: " << arr8.toString() << "\n\n";
    
    std::cout << "тесты пройдены\n";
    
    return 0;
}