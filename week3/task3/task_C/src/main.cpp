#include <iostream>
using namespace std;

float getMedianWithSort(int* arr, int size) {
    int temp;

    // Сортируем массив методом пузырька
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Находим медиану
    if (size % 2 == 1)
        return arr[size / 2];
    else 
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0; // Используем 2.0 для получения float
}

int main() {
    int arr[] = {41, 71, 62, 55, 13, 11, 37};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Выводим изначальный массив
    cout << "Изначальный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Находим медиану
    float median = getMedianWithSort(arr, size);

    // Выводим отсортированный массив
    cout << "Отсортированный массив: ";
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Выводим медиану
    cout << "Медиана массива: " << median << endl;
}
