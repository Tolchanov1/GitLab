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
            BookList* bookList = new BookList(); // ������� ������ ���� �����������
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

                bookList->addBook(Book(title, author, pageCount)); // ��������� �����
            }

            std::cout << "\n������ ����: " << std::endl;
            bookList->displayBooks(); // ���������� ������ ����

            Book* thickestBook = bookList->findThickestBook();
            if (thickestBook) {
                std::cout << "\n����� ������� �����: " << thickestBook->title
                    << " (�����: " << thickestBook->author
                    << ", �������: " << thickestBook->pageCount << ")\n";
            }
            else {
                std::cout << "������ ���� ����.\n";
            }

            delete bookList; // ������� ������ ����

            std::cout << "\n������ ������ ��� �����? (y/n): ";
            std::cin >> choice;

        } while (choice == 'y' || choice == 'Y');
    }
}