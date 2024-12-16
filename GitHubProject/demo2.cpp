#include <iostream>
#include "lab2.h"
#include <Windows.h>    

namespace lab02 {
    void runDemo() {
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        setlocale(LC_ALL, "RUS");

        BookList bookList;
        char choice;

        do {
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

                bookList.addBook(Book(title, author, pageCount));
            }

            std::cout << "\nСписок книг: " << std::endl;
            bookList.displayBooks();

            std::vector<Book*> thickestBooks = bookList.findThickestBook();
            if (!thickestBooks.empty()) {
                std::cout << "\nСписок толстых книг: " << std::endl;
                for (const auto& book : thickestBooks) {
                    std::cout << book->title << " (Автор: " << book->author
                        << ", Страниц: " << book->pageCount << ")\n";
                }
            }
            else {
                std::cout << "Список книг пуст.\n";
            }

            std::cout << "\nХотите ввести еще книги? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }
}