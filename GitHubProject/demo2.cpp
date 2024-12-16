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

            std::cout << "������� ���������� ����: ";
            std::cin >> numberOfBooks;

            for (int i = 0; i < numberOfBooks; ++i) {
                std::string title, author;
                int pageCount;

                std::cout << "\n������� �������� �����: ";
                std::cin.ignore(); // ���������� ������ ����� ������
                std::getline(std::cin, title);

                std::cout << "������� ������ �����: ";
                std::getline(std::cin, author);

                std::cout << "������� ���������� �������: ";
                std::cin >> pageCount;

                bookList.addBook(Book(title, author, pageCount));
            }

            std::cout << "\n������ ����: " << std::endl;
            bookList.displayBooks();

            std::vector<Book*> thickestBooks = bookList.findThickestBook();
            if (!thickestBooks.empty()) {
                std::cout << "\n������ ������� ����: " << std::endl;
                for (const auto& book : thickestBooks) {
                    std::cout << book->title << " (�����: " << book->author
                        << ", �������: " << book->pageCount << ")\n";
                }
            }
            else {
                std::cout << "������ ���� ����.\n";
            }

            std::cout << "\n������ ������ ��� �����? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }
}