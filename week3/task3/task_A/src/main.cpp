#include <iostream>
#include "ArrayHandler.hpp"

using namespace std;

int main() {
    int n;

    cout << "Введите количество элементов массива: ";
    cin >> n;

    if (n < 1) {
        cout << "Некорректное количество элементов!" << endl;
        return 1;
    }

    ArrayHandler arrayHandler(n);
    arrayHandler.inputArray();

    int maxCount = arrayHandler.countMaxOccurrences();
    cout << "Количество чисел, равных максимальному: " << maxCount << endl;
}
