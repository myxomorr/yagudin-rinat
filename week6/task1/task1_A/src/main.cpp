#include <iostream>
#include <list>
#include "../include/perms.hpp"

using namespace std; // Добавлено использование пространства имен

int main() {
    list<int> input = {1, 2, 3}; // Исходный список чисел
    list<list<int>> permutations = getPermutations(input); // Получаем перестановки
    
    // Выводим все перестановки
    for (const auto &perm : permutations) {
        cout << "[";
        for (auto it = perm.begin(); it != perm.end(); ++it) {
            cout << *it;
            if (next(it) != perm.end()) cout << ", "; // Добавляем запятую между элементами
        }
        cout << "]\n"; // Печатаем закрывающую скобку
    }

    return 0; // Завершаем программу
}
