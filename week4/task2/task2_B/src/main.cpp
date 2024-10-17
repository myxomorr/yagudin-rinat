#include <iostream>
#include "../include/ipChecker.hpp"


int main() {
    string ipV6;
    cout << "Введите ipV6: ";
    cin >> ipV6;
    bool answer = ipChecker(ipV6);
    if (answer) { // Проверка на подходящий email
        cout << ipV6 << " - верный" << endl;
    } else {
        cout << ipV6 << " - не верный" << endl;
    }
}
