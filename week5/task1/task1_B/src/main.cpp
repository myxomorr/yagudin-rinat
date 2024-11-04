#include <iostream>
#include <string>
#include "../include/ShannonEntropy.hpp"
#include "../include/readFile.hpp"

using namespace std;

int main() {
    string filename;;
    cout << "Введите имя файла: ";
    cin >> filename;
    
    // Чтение содержимого файла в строку
    string input = readFileToString(filename);

    // Проверка на пустую строку
    if (input.empty()) {
        cout << "Ошибка: файл пуст или не удалось его открыть." << endl;
        return 1; // Завершение программы с ошибкой
    }

    double entropy = calculateShannonEntropy(input); // Расчет энтропии
    printFormatted(entropy); // Вывод результата с двумя знаками после запятой
    cout << endl;

    return 0; // Завершение программы
}
