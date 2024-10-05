#include <iostream>
#include "../include/BankAccount.hpp"

int main() {
    BankAccount account("1111");
    
    account.deposit(100);
    cout << "Баланс: " << account.getBalance() << endl;

    if (account.withdraw(50)) {
        cout << "Снято 550. Баланс: " << account.getBalance() << endl;
    } else {
        cout << "Недостаточно средств для снятия." << endl;
    }

    if (account.withdraw(60)) {
        cout << "Снято 600. Баланс: " << account.getBalance() << endl;
    } else {
        cout << "Недостаточно средств для снятия." << endl;
    }

    return 0;
}