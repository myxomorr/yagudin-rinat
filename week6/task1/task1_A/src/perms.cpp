#include "../include/perms.hpp"
#include <algorithm>

using namespace std; // Добавлено использование пространства имен

// Рекурсивная функция для генерации перестановок
void perms(list<int> &nums, list<int>::iterator start, list<list<int>> &result) {
    // Если достигнут конец списка, добавляем текущую перестановку в результат
    if (start == nums.end()) {
        result.push_back(nums);
        return;
    }
    
    // Перебираем элементы, начиная с текущего итератора
    for (auto it = start; it != nums.end(); ++it) {
        // Меняем местами элемент с текущим итератором и элемент с итератором start
        iter_swap(start, it);
        
        // Рекурсивно вызываем функцию для следующего итератора
        perms(nums, next(start), result);
        
        // Возвращаем список в исходное состояние (backtrack)
        iter_swap(start, it);
    }
}

// Функция для получения всех перестановок
list<list<int>> getPermutations(list<int> nums) {
    list<list<int>> result; // Список для хранения результатов
    perms(nums, nums.begin(), result); // Запускаем рекурсивную функцию
    return result; // Возвращаем все перестановки
}
