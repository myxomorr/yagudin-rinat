#include "../include/AuthorBook.hpp"

int main() {
    Author author("Федор Достоевскский", 1821);
    Book book("Преступление и наказание", author);

    cout << "Название книги: " << book.getTitle() << endl;
    cout << "Имя автора: " << book.getAuthor().getName() << endl;
    cout << "Год рождения автора: " << book.getAuthor().getBirthYear() << endl;

    return 0;
}