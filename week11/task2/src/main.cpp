#include <iostream>
#include <string>
#include "../include/entropy_calculator.hpp"

int main() {
    std::string filename;
    std::cout << "Введите путь к файлу: ";
    std::getline(std::cin, filename);

    // Вычисление энтропии в параллельном режиме
    double entropy = calculate_entropy_parallel(filename);

    if (entropy != -1) {
        std::cout << "Общая энтропия: " << entropy << std::endl;
    }

    return 0;
}
