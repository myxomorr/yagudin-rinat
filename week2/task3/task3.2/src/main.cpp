#include "CarProgram.hpp"

int main() {
    Engine engine(150);
    Car car("Toyota Camry", engine); 
    Passenger passenger1("Иван");
    Passenger passenger2("Коля");
    
    car.addPassenger(passenger1);
    car.addPassenger(passenger2);
    
    Passenger passenger3("Алексей");
    car.addPassenger(passenger3);
    car.displayInfo();
    car.removePassenger("Иван");
    car.displayInfo();
    car.removePassenger("Петр");

    return 0;
}
