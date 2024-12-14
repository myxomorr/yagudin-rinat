#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <vector>
#include <map>

// Проверка числа на простоту
bool isPrime(int n);

// Функция для работы в многозадачности с механизмом Work Stealing
void workStealing(int start, int end, std::vector<int>& results);

// Функция для равномерного распределения задач
void shuffleWork(int start, int end, std::vector<int>& results);

// Функция для запуска вычислений с Work Stealing
void runWorkStealing(int start, int end, int numThreads);

// Функция для запуска вычислений с Shuffle
void runShuffle(int start, int end, int numThreads);

// Функция для загрузки конфигурации из файла
std::map<std::string, int> loadConfig(const std::string& filename);

#endif // FUNCTIONS_HPP
