#include <iostream>
#include <cmath>
using namespace std;

class Octagon{
    private:
        double innerR;
    public:
        void inputInnerRadius(){
            cout << "Значение внут. Радиуса: ";
            cin >> innerR;
        }

        double calcArea() const {
            return 2*(1+sqrt(2)) * innerR*innerR;
        }

        double calcPerimeter() const {
            return 8 * innerR * (sqrt(2)+1);
        }
    
};