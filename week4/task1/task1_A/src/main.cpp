#include <iostream>
#include <string>
#include "../include/countOccurrences.hpp"

using namespace std;

int main() {
    string searchStr; // Строка для поиска
    cout << "Что ищем: ";
    cin >> searchStr;

    int N; // Количество строк для поиска
    cout << "Введите количество строк: ";
    cin >> N;

    string searchIn[10]; // Массив строк для поиска (размер 10, можно изменить)
    cout << "Где ищем:\n";
    for (int i = 0; i < N; ++i) {
        cin >> searchIn[i];
    }

    int result = countOccurrences(searchStr, searchIn, N);
    cout << result << endl;
}
