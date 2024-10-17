#include <regex>
#include <string>
#include "../include/emailChecker.hpp"
using namespace std;

bool emailChecker(const string& email) {
    // Определение регулярного выражения
    const regex pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9]+\.[a-zA-Z]{2,})");
    // Сопоставление строки с регулярным выражением
    return regex_match(email, pattern);
}