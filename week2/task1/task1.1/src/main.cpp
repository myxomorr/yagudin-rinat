#include <iostream>
#include "../include/User.hpp"

int main(){
    User User1("Ivan", 20);
    User User2("Misha",30);
    User User3("Anton",10);

    cout << "User 1: " << User1.getName() << "\n Age: " << User1.getAge() << endl;
    cout << "User 2: " << User2.getName() << "\n Age: " << User2.getAge() << endl;
    cout << "User 3: " << User3.getName() << "\n Age: " << User3.getAge() << endl;  

    return 0;      
}