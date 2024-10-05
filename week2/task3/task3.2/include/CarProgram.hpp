#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    int power;

public:
    Engine(int power) : power(power) {}
    int getPower() const {
        return power;
    }
};

class Passenger {
private:
    string name;

public:
    Passenger(const string& name) : name(name) {}
    string getName() const {
        return name;
    }
};

class Car {
private:
    string model;
    Engine engine;
    Passenger* passenger1;
    Passenger* passenger2;

public:
    Car(const string& model, const Engine& engine)
        : model(model), engine(engine), passenger1(nullptr), passenger2(nullptr) {}

    void addPassenger(Passenger* passenger) {
        if (passenger1 == nullptr) {
            passenger1 = passenger;
        } else if (passenger2 == nullptr) {
            passenger2 = passenger;
        } else {
            cout << "В автомобиле нет места для третьего пассажира." << endl;
        }
    }

    void removePassenger(Passenger* passenger) {
        if (passenger1 == passenger) {
            passenger1 = nullptr;
        } else if (passenger2 == passenger) {
            passenger2 = nullptr;
        } else {
            cout << "Пассажир не найден." << endl;
        }
    }

    void displayInfo() const {
        cout << "Модель автомобиля: " << model << endl;
        cout << "Мощность двигателя: " << engine.getPower() << " л.с." << endl;
        cout << "Пассажиры: " << endl;
        if (passenger1) {
            cout << "1. " << passenger1->getName() << endl;
        }
        if (passenger2) {
            cout << "2. " << passenger2->getName() << endl;
        }
        if (!passenger1 && !passenger2) {
            cout << "Нет пассажиров." << endl;
        }
    }
};