#include "../include/ShannonEntropy.hpp"
#include <cmath>

using namespace std;

// Функция для расчета энтропии по Шеннону
double calculateShannonEntropy(const string& input) {
    int frequency[256] = {0}; // Массив для хранения частоты символов
    int length = 0; // Длина строки

    // Подсчет частоты каждого символа
    for (char c : input) {
        frequency[(unsigned char)c]++; // Увеличиваем частоту символа
        length++; // Увеличиваем длину строки
    }

    double entropy = 0.0; // Переменная для хранения энтропии

    // Расчет энтропии
    for (int i = 0; i < 256; ++i) {
        if (frequency[i] > 0) { // Если символ встречается
            double probability = static_cast<double>(frequency[i]) / length; // Вероятность символа
            entropy -= probability * log2(probability); // Формула Шеннона
        }
    }

    return entropy; // Возвращаем рассчитанную энтропию
}
