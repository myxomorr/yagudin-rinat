#include <iostream>
using namespace std;

bool LeepYear(int year) {    // проверка високосного года
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

int DaysInMonth(int month, int year) {  // сколько дней в месяце
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
    case 4: case 6: case 9: case 11: return 30; 
    case 2: if (LeepYear(year)) {return 29;} else {return 28;}
    default: return 0;
    }
}

int main(){

    int year;
    cout << "Введите год: ";
    cin >> year;
    int month;
    cout << "\nВведите месяц: ";
    cin >> month;
    int days = DaysInMonth(month, year);
    cout << "\nКол-во дней в " << month << " месяце " << year << " года: " << days << endl;
}
