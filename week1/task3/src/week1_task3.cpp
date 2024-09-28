#include <iostream>
#include <cmath>

using namespace std;

int main(){  //task3
    int a;
    cout << "Введите длину ребра: " << endl;
    cin >> a;
    double volume = (5* (3+sqrt(5)))/ 12 * pow(a,3);
    cout << "Объем равен: " << volume << endl;
    return 0;
}