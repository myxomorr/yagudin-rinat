#include <iostream>
#include "MergeSort.hpp"

using namespace std;

int main() {
    int arr[] = {1, 4, 4, 6, 8, 9, 3};
    int length = sizeof(arr) / sizeof(int);

    cout << "Массив до вызова mergeSort(): ";
    printArray(arr, length);

    MergeSort mergeSort; 
    mergeSort.sort(arr, length); 

    cout << "Массив после вызова mergeSort(): ";
    printArray(arr, length);

    return 0;
}
