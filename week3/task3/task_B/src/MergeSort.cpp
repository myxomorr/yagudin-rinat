#include "MergeSort.hpp"
#include <iostream>
using namespace std;

// Функция для вывода массива
void printArray(int* arr, int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Функция для слияния подмассивов
void MergeSort::merge(int* arr, int low, int mid, int high) {
    int i, j, k;
    int lengthLeft = mid - low + 1;
    int lengthRight = high - mid;

    // Создание временных массивов для хранения левого и правого подмассивов
    int arrLeft[lengthLeft], arrRight[lengthRight];

    // Копирование данных из основного массива во временные массивы
    for (int a = 0; a < lengthLeft; a++) {
        arrLeft[a] = arr[low + a];
    }
    for (int a = 0; a < lengthRight; a++) {
        arrRight[a] = arr[mid + 1 + a];
    }

    i = 0;
    j = 0;
    k = low;

    while (i < lengthLeft && j < lengthRight) {
        // Проверка и размещение меньшего числа из обоих временных массивов в основной массив
        if (arrLeft[i] <= arrRight[j]) {
            arr[k] = arrLeft[i];
            i++;
        } else {
            arr[k] = arrRight[j];
            j++;
        }
        k++;
    }

    // Копирование оставшихся элементов левого подмассива (если есть)
    while (i < lengthLeft) {
        arr[k] = arrLeft[i];
        k++;
        i++;
    }

    // Копирование оставшихся элементов правого подмассива (если есть)
    while (j < lengthRight) {
        arr[k] = arrRight[j];
        k++;
        j++;
    }
}

// Рекурсивный метод сортировки
void MergeSort::mergeSort(int* arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2; // Вычисление среднего
   
        mergeSort(arr, low, mid); // Рекурсивный вызов функции mergeSort() для деления массива на подмассивы
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}


void MergeSort::sort(int* arr, int length) {
    mergeSort(arr, 0, length - 1);
}
