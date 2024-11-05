#include <iostream>
#include <vector>
#include "../include/removeDublicates.hpp"

using namespace std;

int main() {
    // Вводим размер массива
    int n;
    cout << "Введите количество элементов в массиве: ";
    cin >> n;

    // Создаем вектор для ввода элементов
    vector<int> inputArray(n);

    // Вводим элементы массива
    cout << "Введите элементы массива: ";
    for (int i = 0; i < n; ++i) {
        cin >> inputArray[i];
    }

    // Получаем массив без дубликатов
    vector<int> result = removeDuplicates(inputArray);

    // Выводим исходный массив
    cout << "\n Исходный массив: ";
    for (int num : inputArray) {
        cout << num << " ";
    }
    cout << endl;

    // Выводим массив без дубликатов
    cout << "Массив без дубликатов: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
