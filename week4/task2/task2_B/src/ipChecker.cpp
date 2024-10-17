#include <regex>
#include <string>
#include "../include/ipChecker.hpp"
using namespace std;

bool ipChecker(const string& ipV6) {
    // Определение регулярного выражения
    const regex pattern(R"(^([0-9a-fA-F]{4}:){7}[0-9a-fA-F]{4}$)");
    // Сопоставление строки с регулярным выражением
    return regex_match(ipV6, pattern);
}