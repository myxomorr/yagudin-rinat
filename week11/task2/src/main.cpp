#include <iostream>
#include <string>
#include "../include/entropy_calculator.hpp"

int main() {
    const std::string filename = "src/large_file.txt";

    // Вычисление энтропии в параллельном режиме
    double entropy = calculate_entropy_parallel(filename);

    if (entropy != -1) {
        std::cout << "Общая энтропия: " << entropy << std::endl;
    }

    return 0;
}
