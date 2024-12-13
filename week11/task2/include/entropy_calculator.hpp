#include <string>
#include <vector>
#include <queue>
#include <mutex>
#include <thread>

// Функция для вычисления энтропии на одном блоке данных
double calculate_entropy(const char* data, size_t size);

// Вспомогательная функция для обработки блоков и вычисления энтропии
void process_block(std::queue<std::vector<char>>& block_queue, double& total_entropy, std::mutex& mutex);

// Основная функция для вычисления энтропии в параллельном режиме
double calculate_entropy_parallel(const std::string& filename);
