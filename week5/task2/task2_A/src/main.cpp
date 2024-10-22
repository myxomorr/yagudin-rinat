#include <iostream>
#include <string>
#include "../include/converter.hpp"

using namespace std;

int main() {
    string input;
    cout << "Введите сообщение для преобразования: ";
    getline(cin, input);

    int choice;
    cout << "Выберите тип преобразования:\n";
    cout << "1. Целое число\n";
    cout << "2. Число с плавающей запятой\n";
    cout << "3. Логическое значение\n";
    cout << "Ваш выбор: ";
    cin >> choice;

    try {
        switch (choice) {
            case 1: {
                int result = stringToInt(input);
                cout << "Результат преобразования в целое число: " << result << endl;
                break;
            }
            case 2: {
                double result = stringToDouble(input);
                cout << "Результат преобразования в число с плавающей запятой: " << result << endl;
                break;
            }
            case 3: {
                bool result = stringToBool(input);
                cout << "Результат преобразования в логическое значение: " << (result ? "true" : "false") << endl;
                break;
            }
            default:
                cout << "Ошибка: Неверный выбор." << endl;
        }
    } catch (const runtime_error& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
