#include <iostream>
#include "../include/Octagon.hpp"

int main(){
    Octagon Octagon;

    Octagon.inputInnerRadius();

    cout << "Area: " << Octagon.calcArea() << endl;
    cout << "Perimeter: " << Octagon.calcPerimeter() << endl;

    return 0;
}