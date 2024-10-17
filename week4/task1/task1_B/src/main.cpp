#include <iostream>
#include <string>
#include "../include/ShannonEntropy.hpp"

using namespace std;

// Функция для форматирования вывода с двумя знаками после запятой
void printFormatted(double value) {
    int integerPart = static_cast<int>(value);
    int decimalPart = static_cast<int>((value - integerPart) * 100); // Получаем две цифры после запятой

    // Обработка отрицательных значений
    if (decimalPart < 0) {
        decimalPart = -decimalPart;
    }

    cout << integerPart << ".";

    // Добавляем ведущий ноль, если необходимо
    if (decimalPart < 10) {
        cout << "0";
    }
    cout << decimalPart;
}

int main() {
    string input; // Входная строка
    cout << "Введите строку: ";
    getline(cin, input); // Ввод строки

    // Проверка на пустую строку
    if (input.empty()) {
        cout << "Ошибка: введена пустая строка." << endl;
        return 1; // Завершение программы с ошибкой
    }

    double entropy = calculateShannonEntropy(input); // Расчет энтропии
    printFormatted(entropy); // Вывод результата с двумя знаками после запятой
    cout << endl;

    return 0; // Завершение программы
}
