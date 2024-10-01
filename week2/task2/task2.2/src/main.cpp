#include <iostream>
#include "BankAccount.hpp"

int main() {
    BankAccount account("1111");
    
    account.deposit(10000);
    cout << "Баланс: " << account.getBalance() << endl;

    if (account.withdraw(5500)) {
        cout << "Снято 550. Баланс: " << account.getBalance() << endl;
    } else {
        cout << "Недостаточно средств для снятия." << endl;
    }

    if (account.withdraw(200)) {
        cout << "Снято 600. Баланс: " << account.getBalance() << endl;
    } else {
        cout << "Недостаточно средств для снятия." << endl;
    }

    return 0;
}