#include "../include/trapezoid_area.hpp"
#include <cmath>
#include <iostream>
#include <vector>
#include <thread>

double trapezoid_area(double (*f)(double), double a, double b, int n) {
    // Используем метод прямоугольников для интегрирования
    double area = 0.0;
    double step = (b - a) / n;
    
    // Получаем количество потоков, поддерживаемых системой
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) {
        num_threads = 4; // Если нельзя определить количество потоков, используем 4 по умолчанию
    }
    
    std::vector<std::thread> threads;
    std::vector<double> results(num_threads, 0.0); // Для нужного количества потоков

    // Разделим работу на потоки
    for (unsigned int i = 0; i < num_threads; ++i) {
        threads.push_back(std::thread(compute_area, f, a, b, n, i, num_threads, std::ref(results[i])));
    }

    // Ожидаем завершения всех потоков
    for (auto &t : threads) {
        t.join();
    }

    // Суммируем результаты из всех потоков
    for (const auto &result : results) {
        area += result;
    }

    return area;
}

void compute_area(double (*f)(double), double a, double b, int n, unsigned int thread_id, unsigned int num_threads, double &result) {
    double step = (b - a) / n;
    
    // Разделяем интервал [a, b] на части для разных потоков
    double local_a = a + thread_id * (b - a) / num_threads;
    double local_b = a + (thread_id + 1) * (b - a) / num_threads;

    // Метод прямоугольников для численного интегрирования
    double local_area = 0.0;
    for (int i = 0; i < n / num_threads; ++i) {
        double x = local_a + i * step;
        local_area += f(x) * step;
    }
    result = local_area;
}

