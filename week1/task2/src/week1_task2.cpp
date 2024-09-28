#include <iostream>
#include <climits>
#include <float.h>

using namespace std;

int main(){

// Целочисленные значение
    cout << "Char: Min: " << CHAR_MIN << " Max: " << CHAR_MAX << endl; // CHAR занимает 1 байт памяти
    cout << "Short: Min: " << SHRT_MIN << " Max: " << SHRT_MAX << endl; //  SHORT занимает 2 байта памяти
    cout << "Int: Min: " << INT_MIN << " Max: " << INT_MAX << endl; // INT занимает 4 байта памяти
    cout << "Long: Min: " << LONG_MIN << " Max: " << LONG_MAX << endl; // LONG занимает 4/8 байт памяти, в зависимости от архитектуры

// Числа с плавающей точкой
       cout << "Float: Min: " << FLT_MIN << " Max: " << FLT_MAX << endl; // Float занимает 4 байта памяти
       cout << "Double: Min: " << DBL_MIN << " Max: " << DBL_MAX << endl; // Double занимает 8 байт памяти       

}