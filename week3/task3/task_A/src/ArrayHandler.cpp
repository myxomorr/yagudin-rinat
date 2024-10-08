#include <iostream>
#include "ArrayHandler.hpp"

using namespace std;

ArrayHandler::ArrayHandler(int n) {
    size = n;
    data_array = new double[size];
}

ArrayHandler::~ArrayHandler() {
    delete[] data_array;
}

// Метод для ввода массива
void ArrayHandler::inputArray() {
    cout << "Введите элементы массива: ";
    for (int i = 0; i < size; ++i) {
        cin >> data_array[i];
    }
}

// Метод для сортировки массива методом пузырька
void ArrayHandler::bubbleSort() {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data_array[j] > data_array[j + 1]) {
                double temp = data_array[j];
                data_array[j] = data_array[j + 1];
                data_array[j + 1] = temp;
            }
        }
    }
}

// Метод для подсчета максимальных значений
int ArrayHandler::countMaxOccurrences() {
    if (size == 0) return 0;

    bubbleSort();

    double maxNumber = data_array[size - 1]; // Максимальное значение - последний элемент
    int count = 1;

    // Сравниваем с предыдущими элементами
    for (int i = size - 2; i >= 0; --i) {
        if (data_array[i] == maxNumber) {
            count++;
        } else {
            break;
        }
    }

    return count;
}
