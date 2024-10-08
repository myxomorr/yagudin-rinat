#include <iostream>
using namespace std;

string getAge(int age) { 
    if ((age % 10 == 1) && (age % 100 != 11)) {  
        return to_string(age) + " год";
    } else if ((age % 10 >= 2 && age % 10 <= 4) && (age %100 <12 || age %100 >14)) {
        return to_string(age) + " года";
    } else {return to_string(age) + " лет";}

}

int main(){

    int age;
    cout << "Введите возраст: ";
    cin >> age;
    cout << getAge(age) << endl;
}