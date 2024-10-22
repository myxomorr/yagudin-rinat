#include "../include/readFile.hpp"

using namespace std;

void readFile(const string& filename) {
    // Открытие файла
    ifstream file(filename);
    
    // Проверка, удалось ли открыть файл
    if (!file.is_open()) {
        cerr << "Ошибка: Не удалось открыть файл '" << filename << "'." << endl;
        return;
    }

    string line;
    // Чтение файла построчно
    while (getline(file, line)) {
        cout << line << endl; // Вывод строки на экран
    }

    // Проверка на ошибки при чтении файла
    if (file.bad()) {
        cerr << "Ошибка: Проблема при чтении файла." << endl;
    }

    file.close(); // Закрытие файла
}
