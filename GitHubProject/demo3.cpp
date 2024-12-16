#include <iostream>
#include "lab3_a.h"
#include <Windows.h>    

namespace lab03 {
    void runDemo() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, "RUS");

        char choice;

        do {
            BookList* bookList = new BookList(); // Создаем список книг динамически
            int numberOfBooks;

            std::cout << "Введите количество книг: ";
            std::cin >> numberOfBooks;

            for (int i = 0; i < numberOfBooks; ++i) {
                std::string title, author;
                int pageCount;

                std::cout << "\nВведите название книги: ";
                std::cin.ignore(); // Игнорируем символ новой строки
                std::getline(std::cin, title);

                std::cout << "Введите автора книги: ";
                std::getline(std::cin, author);

                std::cout << "Введите количество страниц: ";
                std::cin >> pageCount;

                bookList->addBook(Book(title, author, pageCount)); // Добавляем книгу
            }

            std::cout << "\nСписок книг: " << std::endl;
            bookList->displayBooks(); // Отображаем список книг

            Book* thickestBook = bookList->findThickestBook();
            if (thickestBook) {
                std::cout << "\nСамая толстая книга: " << thickestBook->title
                    << " (Автор: " << thickestBook->author
                    << ", Страниц: " << thickestBook->pageCount << ")\n";
            }
            else {
                std::cout << "Список книг пуст.\n";
            }

            delete bookList; // Удаляем список книг

            std::cout << "\nХотите ввести еще книги? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }
}