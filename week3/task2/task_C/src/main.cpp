#include <iostream>
#include <cmath>

using namespace std;

void sieveOfEratosthenes(int n) {
    // Создаем массив для отметки простых чисел
    bool* isPrime = new bool[n + 1];

    // Изначально считаем все числа простыми
    for (int i = 0; i <= n; i++) {
        isPrime[i] = true;
    }

    // 0 и 1 не являются простыми числами
    isPrime[0] = isPrime[1] = false;

    // Основной алгоритм решета Эратосфена
    for (int p = 2; p <= sqrt(n); p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple <= n; multiple += p) {
                isPrime[multiple] = false; // Отмечаем составные числа
            }
        }
    }

    // Вывод простых чисел
    cout << "Простые числа до " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    // Освобождаем память
    delete[] isPrime;
}

int main() {
    int n;

    cout << "Введите предел для поиска простых чисел: ";
    cin >> n;

    sieveOfEratosthenes(n);

    return 0;
}
