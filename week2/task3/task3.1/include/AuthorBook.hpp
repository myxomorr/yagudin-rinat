#include <iostream>
#include <string>

using namespace std;

class Author {
public:
    Author(string name, int birthYear)
        : name(name), birthYear(birthYear) {}

    string getName() {
        return name;
    }

    int getBirthYear(){
        return birthYear;
    }

    void setName(string name) {
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
    Book(string title, Author author)
        : title(title), author(author) {}

    string getTitle(){
        return title;
    }

    Author getAuthor(){
        return author;
    }

    void setTitle(string title) {
        this->title = title;
    }

    void setAuthor(Author author) {
        this->author = author;
    }

private:
    string title;
    Author author;
};