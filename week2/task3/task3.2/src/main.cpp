#include "../include/CarProgram.hpp"

int main() {
    Engine engine(235);
    Car car("Toyota Land Cruiser", engine);
    Passenger passenger1("Олег");
    Passenger passenger2("Иван");

    car.addPassenger(&passenger1);
    car.addPassenger(&passenger2);
    car.displayInfo();

    car.removePassenger(&passenger2);
    cout << "\nПосле удаления пассажира:" << endl;
    car.displayInfo();

    return 0;
}