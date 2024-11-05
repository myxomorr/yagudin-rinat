#include "../include/maxProfit.hpp"
#include <limits.h>

// Функция для вычисления максимальной прибыли
int maxProfit(const std::list<int>& prices) {
    int minPrice = INT_MAX; // Минимальная цена на момент покупки
    int maxProfit = 0; // Переменная для хранения максимальной прибыли

    // Проходим по всем ценам
    for (int price : prices) {
        // Обновляем минимальную цену
        if (price < minPrice) {
            minPrice = price;
        }
        // Вычисляем прибыль, если продать по текущей цене
        int profit = price - minPrice;
        // Обновляем максимальную прибыль
        if (profit > maxProfit) {
            maxProfit = profit;
        }
    }

    return maxProfit; // Возвращаем максимальную прибыль
}
