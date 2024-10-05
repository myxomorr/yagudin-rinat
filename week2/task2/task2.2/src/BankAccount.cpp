#include "../include/BankAccount.hpp"

BankAccount::BankAccount(string accountNumber) : accountNumber(accountNumber), balance(0.0f) {}

void BankAccount::deposit(float amount) {
    if (amount > 0) {
        balance += amount;
    }
}

bool BankAccount::withdraw(float amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return true;
    }
    return false;
}

float BankAccount::getBalance() const {
    return balance;
}