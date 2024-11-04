#include "../include/readFile.hpp"
#include <iostream>

using namespace std;

int main() {
    string filename;;
    cout << "Введите имя файла: ";
    cin >> filename;

    // Вызов функции для чтения файла
    readFile(filename);

    return 0; // Завершение программы
}
