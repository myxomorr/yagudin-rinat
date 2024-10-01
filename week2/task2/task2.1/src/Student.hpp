#include <string>
#include <iostream>
#include <ctime>
using namespace std;

class Student {
private:
    string name;
    tm birthDate;
    string group;
    int studentId;
    float averageScore;

public:
    Student(string name, tm birthDate, string group, int studentId, float averageScore);
    string getName() const;
    tm getBirthDate() const;
    string getGroup() const;
    int getStudentId() const;
    float getAverageScore() const;
    void setName(const string& name);
    void setBirthDate(const tm& birthDate);
    void setGroup(const string& group);
    void setStudentId(int studentId);
    void setAverageScore(float averageScore);
    int getAge() const;
    string toString() const;
    bool isExcellentStudent() const;
};