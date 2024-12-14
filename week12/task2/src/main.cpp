#include <iostream>
#include <iomanip>
#include <openssl/md5.h>
#include <sstream>
#include <string>
#include <vector>
#include <spdlog/spdlog.h>
#include <chrono>
#include <thread>
#include <mutex>
#include <atomic>

using namespace std;

// Исходный пароль, который мы будем хешировать
const string password = "Qw3t";  
unsigned char targetMD5[MD5_DIGEST_LENGTH]; // Массив для хранения MD5 хеша пароля

// Функция для вычисления MD5 хеша из строки
void computeMD5FromString(const string &str, unsigned char *result) {
    MD5((unsigned char *)str.c_str(), str.length(), result);
}

// Функция для преобразования MD5 в строку
string md5ToString(unsigned char *md) {
    stringstream ss;
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)md[i];
    }
    return ss.str();
}

atomic<bool> found(false);  // Переменная для контроля, что пароль найден
atomic<long long> totalCombinations(0);  // Атомарная переменная для безопасного увеличения счетчика

// Функция для перебора строк в потоке
void bruteForceMD5Thread(int threadId, const string &targetMD5, const string &chars, int len, long long startIdx, long long endIdx) {
    unsigned char result[MD5_DIGEST_LENGTH];

    for (long long index = startIdx; index < endIdx; ++index) {
        // Если пароль найден, прерываем выполнение
        if (found.load()) break;

        // Преобразуем индекс в строку
        string currentStr;
        long long tempIndex = index;
        for (int i = 0; i < len; i++) {
            currentStr = chars[tempIndex % chars.size()] + currentStr;
            tempIndex /= chars.size();
        }

        computeMD5FromString(currentStr, result);
        string computedMD5 = md5ToString(result);

        if (computedMD5 == targetMD5) {
            found.store(true);
            spdlog::info("Thread {}: Found password: {}", threadId, currentStr);
            return;
        }
    }
}

// Функция для перебора всех комбинаций
void bruteForceMD5(const string &targetMD5, int numThreads) {
    const string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";  
    int len = password.length();  // Длина пароля
    long long totalCombinationsCount = pow(chars.size(), len);

    // Делим работу между потоками
    vector<thread> threads;
    long long range = totalCombinationsCount / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        long long startIdx = i * range;
        long long endIdx = (i == numThreads - 1) ? totalCombinationsCount : (i + 1) * range;
        threads.push_back(thread(bruteForceMD5Thread, i, ref(targetMD5), ref(chars), len, startIdx, endIdx));
    }

    for (auto &t : threads) {
        t.join();
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <threads>" << endl;
        return 1;
    }

    int numThreads = 0;  // Объявляем переменную numThreads

    // Чтение количества потоков из аргумента
    string threadsArg = argv[1]; // Строка с количеством потоков (например, threads==4)

    // Проверка, что аргумент содержит "threads=="
    size_t pos = threadsArg.find("threads==");
    if (pos != string::npos) {
        // Извлечение числа из строки
        try {
            numThreads = stoi(threadsArg.substr(pos + 9));  // 9 — это длина строки "threads=="
        } catch (const std::invalid_argument &e) {
            cerr << "Invalid number of threads!" << endl;
            return 1;
        }
    } else {
        cerr << "Usage: " << argv[0] << " <threads==number>" << endl;
        return 1;
    }

    if (numThreads <= 0) {
        cerr << "Invalid number of threads!" << endl;
        return 1;
    }

    // Засекаем время начала выполнения
    auto startTime = chrono::high_resolution_clock::now();

    // Преобразуем пароль в MD5 хеш
    computeMD5FromString(password, targetMD5);
    string targetMD5String = md5ToString(targetMD5);

    spdlog::info("Starting brute force for MD5: {}", targetMD5String);

    bruteForceMD5(targetMD5String, numThreads);

    // Засекаем время окончания выполнения
    auto endTime = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = endTime - startTime;

    // Выводим время выполнения
    spdlog::info("Total execution time: {} seconds", duration.count());

    return 0;
}
