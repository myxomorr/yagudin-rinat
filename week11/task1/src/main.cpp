#include "../include/trapezoid_area.hpp"
#include <iostream>
#include <cmath>

// Пример функции, которая будет использоваться для вычислений
double function(double x) {
    return std::sin(x) * 4 + std::cos(x) + 42*sin(x) - sin(x*x); // Можно написать свою функцию
}

int main() {
    // Начальные данные
    double a = 44.0, b = 48.0;  // Интервал интегрирования
    int n = 10000;  // Количество разбиений

    // Вычисление площади для разных функций
    double area_sin = trapezoid_area(function, a, b, n);

    // Вывод результатов
    std::cout << "Площадь равна: " << area_sin << std::endl;

    return 0;
}
