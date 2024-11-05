#include <iostream>
#include <set>
#include <ctime>
#include "../include/order.h"
#include "../include/customer.h"
#include "../include/product.h"
#include "../include/createDate.h"

using namespace std;

int main() {
    Customer customer(1);

    std::set<Product> products1;
    products1.insert(Product(1, "Конфеты", "Сладости", 10.0));
    products1.insert(Product(2, "Шоколад", "Сладости", 20.0));
    products1.insert(Product(3, "Пряники", "Сладости", 25.0));  

    std::set<Product> products2;
    products2.insert(Product(4, "Хлеб", "Выпечка", 6.0));
    products2.insert(Product(5, "Булка c сыром", "Выпечка", 8.0));
    products2.insert(Product(6, "Вода", "Напитки", 5.0));

    Order order1(1, createDate(2020, 2, 16), createDate(2020, 2, 20), "completed", customer, products1);
    Order order2(2, createDate(2020, 4, 15), createDate(2020, 4, 20), "completed", customer, products2);
    Order order3(3, createDate(2020, 3, 14), createDate(2020, 3, 18), "completed", customer, products2);
    Order order4(4, createDate(2020, 2, 14), createDate(2020, 2, 18), "completed", customer, products2);    

    double sum = 0.0;

    // Суммируем цены продуктов только для заказов в феврале 2020 года
    for (const Order& order : {order1, order2, order3, order4}) {
        time_t orderTime = order.getOrderDate(); // Получаем дату заказа в формате time_t
        tm* orderDate = localtime(&orderTime); // Преобразуем time_t в tm

        // Проверяем, если год 2020 и месяц 2 (февраль)
        if (orderDate->tm_year == 2020 - 1900 && orderDate->tm_mon == 1) {
            for (const Product& product : order.getProducts()) {
                sum += product.getPrice(); // Суммируем цену продукта
            }
        }
    }

    cout << "Сумма цен продуктов в заказах февраля 2020 года: " << sum << endl;

    return 0;
}
