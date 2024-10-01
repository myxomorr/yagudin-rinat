#include <iostream>
#include <string>

using namespace std;

class Author {
public:
    Author(const string& name, int birthYear)
        : name(name), birthYear(birthYear) {}

    string getName() const {
        return name;
    }

    int getBirthYear() const {
        return birthYear;
    }

    void setName(const string& name) {
        this->name = name;
    }

    void setBirthYear(int birthYear) {
        this->birthYear = birthYear;
    }

private:
    string name;
    int birthYear;
};

class Book {
public:
    Book(const string& title, const Author& author)
        : title(title), author(author) {}

    string getTitle() const {
        return title;
    }

    Author getAuthor() const {
        return author;
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    void setAuthor(const Author& author) {
        this->author = author;
    }

private:
    string title;
    Author author;
};