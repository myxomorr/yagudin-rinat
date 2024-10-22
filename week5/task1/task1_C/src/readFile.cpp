#include "../include/readFile.hpp"
#include <sstream>
using namespace std;

string readFileToString(const string& filename) {
    ifstream file(filename);
    string content;

    // Проверка, удалось ли открыть файл
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл '" << filename << "'." << endl;
        return "";
    }

    // Чтение файла в строку
    string line;
    while (getline(file, line)) {
        content += line + "\n"; // Добавляем строку с переносом
    }

    file.close(); // Закрытие файла
    return content; // Возвращаем содержимое файла
}

// Функция для форматирования вывода с двумя знаками после запятой
string formatDouble(double value) {
    int integerPart = static_cast<int>(value);
    int decimalPart = static_cast<int>((value - integerPart) * 100); // Получаем две цифры после запятой

    // Обработка отрицательных значений
    if (decimalPart < 0) {
        decimalPart = -decimalPart;
    }

    stringstream formatted;
    formatted << integerPart << ".";

    // Добавляем ведущий ноль, если необходимо
    if (decimalPart < 10) {
        formatted << "0";
    }
    formatted << decimalPart;

    return formatted.str();
}
