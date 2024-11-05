#include "../include/removeDublicates.hpp"
#include <set>
#include <queue>

using namespace std;

// Функция для удаления дубликатов из входного массива
vector<int> removeDuplicates(const vector<int>& inputArray) {
    set<int> uniqueElements;  // Множество для хранения уникальных элементов
    queue<int> inputQueue;    // Очередь для хранения исходных данных
    vector<int> result;       // Массив для хранения результата

    // Добавляем элементы в очередь
    for (int num : inputArray) {
        inputQueue.push(num);
    }

    // Обрабатываем элементы из очереди
    while (!inputQueue.empty()) {
        int current = inputQueue.front();
        inputQueue.pop();

        // Если элемент еще не встречался, добавляем его в результат
        if (uniqueElements.find(current) == uniqueElements.end()) {
            uniqueElements.insert(current);
            result.push_back(current);
        }
    }

    return result;
}
