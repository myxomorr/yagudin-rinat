#include "AuthorBook.hpp"

int main() {
    Author author("Лев Толстой", 1828);
    Book book("Война и мир", author);

    cout << "Название книги: " << book.getTitle() << endl;
    cout << "Имя автора: " << book.getAuthor().getName() << endl;
    cout << "Год рождения автора: " << book.getAuthor().getBirthYear() << endl;

    // Изменим данные автора
    author.setName("Лев Николаевич Толстой");
    author.setBirthYear(1828);

    // Обновим информацию в книге
    book.setAuthor(author);

    cout << "\nОбновленная информация об авторе:" << endl;
    cout << "Имя автора: " << book.getAuthor().getName() << endl;
    cout << "Год рождения автора: " << book.getAuthor().getBirthYear() << endl;

    return 0;
}