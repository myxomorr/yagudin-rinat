#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Engine {
public:
    Engine(int power) : power(power) {}

    int getPower() const {
        return power;
    }

private:
    int power;
};

class Passenger {
public:
    Passenger(const string& name) : name(name) {}

    string getName() const {
        return name;
    }

private:
    string name;
};

class Car {
public:
    Car(const string& model, const Engine& engine)
        : model(model), engine(engine) {}

    void addPassenger(const Passenger& passenger) {
        if (passengers.size() < 2) {
            passengers.push_back(passenger);
        } else {
            cout << "В автомобиле уже есть 2 пассажира." << endl;
        }
    }

    void removePassenger(const string& name) {
        for (auto it = passengers.begin(); it != passengers.end(); ++it) {
            if (it->getName() == name) {
                passengers.erase(it);
                cout << "Пассажир " << name << " удалён." << endl;
                return;
            }
        }
        cout << "Пассажир с именем " << name << " не найден." << endl;
    }

    void displayInfo() const {
        cout << "Модель автомобиля: " << model << endl;
        cout << "Мощность двигателя: " << engine.getPower() << " л.с." << endl;
        cout << "Пассажиры:" << endl;
        for (const auto& passenger : passengers) {
            cout << "- " << passenger.getName() << endl;
        }
        if (passengers.empty()) {
            cout << "Нет пассажиров." << endl;
        }
    }

private:
    string model;
    Engine engine;
    vector<Passenger> passengers;
};
