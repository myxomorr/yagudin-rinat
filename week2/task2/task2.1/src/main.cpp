#include <iostream>
#include "../include/Student.hpp"

int main() {
    tm birthDate1 = {};
    birthDate1.tm_year = 2005 - 1900;
    birthDate1.tm_mon = 5;
    birthDate1.tm_mday = 10;

    Student student1("Иван Иванов", birthDate1, "23ИБ1б", 123456, 4.9);
    
    cout << student1.toString() << endl;
    cout << "Возраст: " << student1.getAge() << " лет" << endl;
    cout << "Отличник: " << (student1.isExcellentStudent() ? "Да" : "Нет") << endl;

    return 0;
}