#include <iostream>
using namespace std;

bool PlayBadminton(string temp, string precipitation, bool wind, string humidity) {
    if ((temp == "жарко" || temp == "тепло") && (precipitation == "ясно" ) && (wind == false) && (humidity == "низкая")) {  // проверка на условия 
        return true;
    }
    return false; // условия не удовлетворяют
}


int main() {
    string temp, precipitation, humidity;
    bool wind;

    cout << "Введите температуру (жарко/тепло/холодно): ";
    cin >> temp;
    cout << "Введите осадки (ясно/облачно/дождь/снег/град): ";
    cin >> precipitation;
    cout << "Есть ветер? (1 - да, 0 - нет): ";
    cin >> wind;
    cout << "Введите влажность (высокая/низкая): ";
    cin >> humidity;

    if (PlayBadminton(temp, precipitation, wind, humidity)) {
        cout << "Да, хотите играть в бадминтон!" << endl;} 
        else {
        cout << "Нет, не хотите играть в бадминтон." << endl;}
}