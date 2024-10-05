#include "../include/User.hpp"

string User::getName(){
    return name;
}

void User::setName(string name){
    this->name = name;
}

int User::getAge(){
    return age;
}

void User::setAge(int age){
    this->age = age;
}

User::User() : name("Unknown"), age(0) {}

User::User(string name,int age){
    this->name = name;
    this->age = age;
}