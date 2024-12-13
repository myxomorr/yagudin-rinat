#include "../include/entropy_calculator.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

// Функция для вычисления энтропии на одном блоке данных
double calculate_entropy(const char* data, size_t size) {
    std::vector<int> frequency(256, 0);

    // Подсчет частоты символов
    for (size_t i = 0; i < size; ++i) {
        frequency[static_cast<unsigned char>(data[i])]++;
    }

    // Вычисление энтропии
    double entropy = 0.0;
    for (int freq : frequency) {
        if (freq > 0) {
            double p = static_cast<double>(freq) / size;
            entropy -= p * std::log2(p);
        }
    }

    return entropy;
}

// Вспомогательная функция для обработки блоков и вычисления энтропии
void process_block(std::queue<std::vector<char>>& block_queue, double& total_entropy, std::mutex& mutex) {
    while (true) {
        std::vector<char> block;

        // Заходим в критическую секцию для безопасного извлечения блока
        {
            std::lock_guard<std::mutex> lock(mutex);
            if (!block_queue.empty()) {
                block = block_queue.front();
                block_queue.pop();
            }
        }

        // Если блоков нет, завершаем выполнение потока
        if (block.empty()) {
            break;
        }

        // Вычисляем энтропию для текущего блока
        double entropy = calculate_entropy(block.data(), block.size());

        // Обновляем суммарную энтропию в общей переменной, защищая доступ мьютексом
        {
            std::lock_guard<std::mutex> lock(mutex);
            total_entropy += entropy;
        }
    }
}

// Функция для вычисления энтропии в параллельном режиме
double calculate_entropy_parallel(const std::string& filename) {
    // Получаем количество доступных потоков
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) {
        num_threads = 4;  // Если количество потоков не определено, используем 4 потока
    }

    const size_t available_memory = 8LL * 1024 * 1024 * 1024;  // 8 ГБ
    const size_t block_size = available_memory / num_threads;  // Размер блока для каждого потока

    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return -1;
    }

    // Получаем размер файла
    file.seekg(0, std::ios::end);
    size_t file_size = file.tellg();
    file.seekg(0, std::ios::beg);

    // Очередь для блоков
    std::queue<std::vector<char>> block_queue;

    // Чтение файла блоками
    while (file.tellg() < file_size) {
        size_t remaining_size = file_size - file.tellg();
        size_t current_block_size = std::min(block_size, remaining_size);

        // Загружаем блок данных в память
        std::vector<char> block(current_block_size);
        file.read(block.data(), current_block_size);

        // Добавляем блок в очередь
        block_queue.push(block);
    }

    // Общая переменная для хранения суммарной энтропии
    double total_entropy = 0.0;

    // Мьютекс для синхронизации доступа к очереди и переменной total_entropy
    std::mutex mutex;

    // Запускаем потоки
    std::vector<std::thread> threads;
    for (unsigned int i = 0; i < num_threads; ++i) {
        // Передаем блоки для обработки
        threads.push_back(std::thread([&block_queue, &total_entropy, &mutex]() {
            process_block(block_queue, total_entropy, mutex);
        }));
    }

    // Ожидаем завершения всех потоков
    for (auto& t : threads) {
        t.join();
    }

    return total_entropy;
}
