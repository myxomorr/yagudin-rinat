#include <iostream>
#include "../include/replacer.hpp"

using namespace std;

int main() {
    string input; // Переменная для ввода строки

    // Запрашиваем ввод от пользователя
    cout << "Введите строку: ";
    getline(cin, input);

    // Вызываем функцию для замены повторяющихся символов
    string output = replaceRepeats(input);

    // Выводим результат
    cout << "Результат: " << output << endl;

    return 0; // Завершаем программу
}
