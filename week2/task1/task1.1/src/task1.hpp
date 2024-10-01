#include <iostream>
#include <string>
using namespace std;

class User{
    private:

        string name;
        int age;

    public:

        string  getName();
        void setName(string name);

        int getAge();
        void setAge(int age);
        
        User();
        User(string name, int age);

};