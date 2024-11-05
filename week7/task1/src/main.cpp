#include "../include/mostFrequentChar.hpp"

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::cin >> input;
    
    // Получаем пару (символ, частота)
    auto result = mostFrequentChar(input);

    // Выводим результат в нужном формате: ['символ', количество]
    std::cout << "['" << result.first << "', " << result.second << "]" << std::endl;

    return 0;
}
