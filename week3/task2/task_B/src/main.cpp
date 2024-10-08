#include <iostream>
#include <cmath>
using namespace std;

double SquareRoot(double number){
    double answer = number;
    while (abs(answer*answer - number) >= 0.0001) // цикл идет пока точность не будет 0.0001
    {
        answer = (answer + number / answer)/2;
    }
    return answer;    
}

int main(){
    double number;
    cout << "Введите число для нахождения кв.корня: ";
    cin >> number;
    cout << SquareRoot(number) << endl;
}