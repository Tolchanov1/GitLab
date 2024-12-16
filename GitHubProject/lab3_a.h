#pragma once

#include <string>

namespace lab03 {
    void runDemo();

    //  ласс, описывающий книгу
    class Book {
    public:
        std::string title;
        std::string author;
        int pageCount;

        Book(const std::string& title, const std::string& author, int pageCount);
    };

    //  ласс, представл€ющий узел списка
    class Node {
    public:
        Book book;           //  нига в узле
        Node* next;          // ”казатель на следующий узел

        Node(const Book& book);
    };

    //  ласс, представл€ющий односв€зный список книг
    class BookList {
    private:
        Node* head;           // ”казатель на голову списка
    public:
        BookList();
        ~BookList();

        void addBook(const Book& book);    // ћетод дл€ добавлени€ книги
        Book* findThickestBook();          // ћетод дл€ поиска самой толстой книги
        void displayBooks() const;         // ћетод дл€ отображени€ списка книг
    };
}