#include "../include/Student.hpp"
#include <iomanip>
#include <sstream>

Student::Student(string name, tm birthDate, string group, int studentId, float averageScore)
    : name(name), birthDate(birthDate), group(group), studentId(studentId), averageScore(averageScore) {}

string Student::getName() const {
    return name;
}

tm Student::getBirthDate() const {
    return birthDate;
}

string Student::getGroup() const {
    return group;
}

int Student::getStudentId() const {
    return studentId;
}

float Student::getAverageScore() const {
    return averageScore;
}

void Student::setName(const string& name) {
    this->name = name;
}

void Student::setBirthDate(const tm& birthDate) {
    this->birthDate = birthDate;
}

void Student::setGroup(const string& group) {
    this->group = group;
}

void Student::setStudentId(int studentId) {
    this->studentId = studentId;
}

void Student::setAverageScore(float averageScore) {
    this->averageScore = averageScore;
}

int Student::getAge() const {
    time_t now = time(nullptr);
    tm* currentTime = localtime(&now);
    int age = currentTime->tm_year - birthDate.tm_year;
    if (currentTime->tm_mon < birthDate.tm_mon || 
        (currentTime->tm_mon == birthDate.tm_mon && currentTime->tm_mday < birthDate.tm_mday)) {
        age--;
    }
    return age;
}

string Student::toString() const {
    ostringstream oss;
    oss << "Имя: " << name << "\n"
        << "Дата рождения: " << put_time(&birthDate, "%Y-%m-%d") << "\n"
        << "Группа: " << group << "\n"
        << "Код студента: " << studentId << "\n"
        << "Средний балл: " << averageScore;
    return oss.str();
}

bool Student::isExcellentStudent() const {
    return averageScore >= 4.8;
}