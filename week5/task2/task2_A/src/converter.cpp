#include "../include/converter.hpp"
#include <string>
#include <stdexcept>

using namespace std;

// Функция для преобразования строки в целое число
int stringToInt(const string& str) {
    try {
        return stoi(str);
    } catch (invalid_argument&) {
        throw runtime_error("Невозможно преобразовать строку в целое число.");
    } catch (out_of_range&) {
        throw runtime_error("Число выходит за пределы диапазона целого числа.");
    }
}

// Функция для преобразования строки в число с плавающей запятой
double stringToDouble(const string& str) {
    try {
        return stod(str);
    } catch (invalid_argument&) {
        throw runtime_error("Невозможно преобразовать строку в число с плавающей запятой.");
    } catch (out_of_range&) {
        throw runtime_error("Число выходит за пределы диапазона числа с плавающей запятой.");
    }
}

// Функция для преобразования строки в логическое значение
bool stringToBool(const string& str) {
    if (str == "true") return true;
    if (str == "false") return false;
    throw runtime_error("Невозможно преобразовать строку в логическое значение. Ожидается 'true' или 'false'.");
}
