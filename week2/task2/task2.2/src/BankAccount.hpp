#include <string>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    float balance;

public:
    BankAccount(string accountNumber);
    void deposit(float amount);
    bool withdraw(float amount);
    float getBalance() const;
};