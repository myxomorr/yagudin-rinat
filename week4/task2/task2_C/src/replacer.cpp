#include "../include/replacer.hpp"
#include <regex>

// Реализация функции replaceRepeats
std::string replaceRepeats(const std::string& input) {
    // Регулярное выражение для поиска символов, повторяющихся ≥ 3 раз
    std::regex pattern("(.)\\1{2,}");
    // Замена найденных символов на один символ
    return std::regex_replace(input, pattern, "$1");
}
