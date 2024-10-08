#include <iostream>
#include <string>
using namespace std;

string Pyramid(int height){
    string pyramid;
    for (int i = 1; i <= height; i++)
    {
        pyramid += string(height-i, ' ');
        pyramid += string(i,'#') + ' ';
        pyramid += string(i,'#');
        pyramid += "\n";
    }
    return pyramid;
}


int main(){

    int height;
    cout << "Высота пирамиды: ";
    cin >> height;
    cout << Pyramid(height);
}