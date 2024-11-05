#include "../include/mostFrequentChar.hpp"

std::pair<char, int> mostFrequentChar(const std::string& s) {
    std::map<char, int> frequencyMap;

    // Проходим по каждому символу строки и увеличиваем его частоту
    for (char c : s) {
        frequencyMap[c]++;
    }

    // Ищем символ с максимальной частотой
    char mostFrequent = s[0];
    int maxFrequency = frequencyMap[mostFrequent];

    for (const auto& pair : frequencyMap) {
        if (pair.second > maxFrequency) {
            mostFrequent = pair.first;
            maxFrequency = pair.second;
        }
    }

    // Возвращаем результат как пару символа и его количества
    return {mostFrequent, maxFrequency};
}
