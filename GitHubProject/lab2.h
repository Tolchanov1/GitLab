#pragma once

#include <string>
#include <vector>

namespace lab02 {
    void runDemo();

    // Класс, описывающий книгу
    class Book {
    public:
        std::string title;   // Название книги
        std::string author;  // Автор книги
        int pageCount;       // Количество страниц в книге

        Book(const std::string& title, const std::string& author, int pageCount);
    };

    // Класс, представляющий узел списка
    class Node {
    public:
        Book book;           // Книга в узле
        Node* next;          // Указатель на следующий узел

        Node(const Book& book);
    };

    // Класс, представляющий односвязный список книг
    class BookList {
    private:
        Node* head;           // Указатель на голову списка
    public:
        BookList();
        ~BookList();

        void addBook(const Book& book);    // Метод для добавления книги
        std::vector<Book*> findThickestBook();          // Метод для поиска самой толстой книги
        void displayBooks() const;         // Метод для отображения списка книг
    };
}

// 1. Вывести все самые толстые книги 

// 2. Добавить в первую лабу int* day_of_week
// В тестовой программе добавить сеттер для того чтобы задавать дни недели с проверкой, а также
// Date * date = ( ... malloc  Выделить память
// потом через free ее освободить. Должно получиться что-то плохое








