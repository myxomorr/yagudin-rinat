#include "../include/countOccurrences.hpp"

using namespace std;

// Функция для подсчета вхождений searchStr в каждом элементе searchIn
int countOccurrences(const string& searchStr, const string searchIn[], int N) {
    int count = 0;
    for (int i = 0; i < N; ++i) {
        size_t pos = searchIn[i].find(searchStr); // Ищем первое вхождение
        while (pos != string::npos) { // Пока есть вхождения
            count++; // Увеличиваем счетчик
            pos = searchIn[i].find(searchStr, pos + 1); // Ищем следующее вхождение
        }
    }
    return count; // Возвращаем общее количество вхождений
}
