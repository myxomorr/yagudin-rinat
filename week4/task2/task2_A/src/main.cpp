#include <iostream>
#include "../include/emailChecker.hpp"


int main() {
    string email;
    cout << "Введите email: ";
    cin >> email;
    bool answer = emailChecker(email);
    if (answer) { // Проверка на подходящий email
        cout << email << " - подходит" << endl;
    } else {
        cout << email << " - не подходит" << endl;
    }
}
