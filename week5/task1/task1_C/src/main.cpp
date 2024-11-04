#include <iostream>
#include <string>
#include <fstream>
#include "../include/ShannonEntropy.hpp"
#include "../include/readFile.hpp" // Подключаем файл для чтения

using namespace std;


int main() {
    string filename;;
    string outputFilename;
    cout << "Введите имя файла для расчета энтропии: ";
    cin >> filename;
    cout << "Введите имя файла для записи результата: ";
    cin >> outputFilename;

    // Чтение содержимого файла в строку
    string input = readFileToString(filename);

    // Проверка на пустую строку
    if (input.empty()) {
        cout << "Ошибка: файл пуст или не удалось его открыть." << endl;
        return 1; // Завершение программы с ошибкой
    }

    double entropy = calculateShannonEntropy(input); // Расчет энтропии

    // Запись результата в файл
    ofstream outputFile(outputFilename);
    if (outputFile.is_open()) {
        outputFile << entropy << endl;
        outputFile.close();
        cout << "Результат записан в файл: " << outputFilename << endl;
    } else {
        cout << "Ошибка: не удалось открыть файл для записи." << endl;
    }

    return 0; // Завершение программы
}
