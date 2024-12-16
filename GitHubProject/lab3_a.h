#pragma once

#include <string>

namespace lab03 {
    void runDemo();

    // �����, ����������� �����
    class Book {
    public:
        std::string title;
        std::string author;
        int pageCount;

        Book(const std::string& title, const std::string& author, int pageCount);
    };

    // �����, �������������� ���� ������
    class Node {
    public:
        Book book;           // ����� � ����
        Node* next;          // ��������� �� ��������� ����

        Node(const Book& book);
    };

    // �����, �������������� ����������� ������ ����
    class BookList {
    private:
        Node* head;           // ��������� �� ������ ������
    public:
        BookList();
        ~BookList();

        void addBook(const Book& book);    // ����� ��� ���������� �����
        Book* findThickestBook();          // ����� ��� ������ ����� ������� �����
        void displayBooks() const;         // ����� ��� ����������� ������ ����
    };
}