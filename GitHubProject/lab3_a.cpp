#include "lab3_a.h"
#include <iostream>

namespace lab03 {

    Book::Book(const std::string& title, const std::string& author, int pageCount)
        : title(title), author(author), pageCount(pageCount) {}

    Node::Node(const Book& book) : book(book), next(nullptr) {}

    BookList::BookList() : head(nullptr) {}

    BookList::~BookList() {
        while (head != nullptr) {
            Node* nextNode = head->next;  // ��������� ��������� �� ��������� ����
            delete head;                  // ������� ������� ����
            head = nextNode;              // ��������� � ���������� ����
        }
    }

    void BookList::addBook(const Book& book) {
        Node* newNode = new Node(book);  // ������� ����� ����
        newNode->next = head;             // ��������� ��������� ���� ��� ������� ������
        head = newNode;                   // ��������� ������ ������ 
    }

    Book* BookList::findThickestBook() {
        if (head == nullptr) return nullptr;

        Node* current = head;
        Book* thickestBook = &current->book; // �������������� ����� ������� ����� ������ ������

        // �������� �� ����� ������
        while (current != nullptr) {
            if (current->book.pageCount > thickestBook->pageCount) {
                thickestBook = &current->book; // ��������� ����� ������� �����
            }
            current = current->next;            // ������� � ���������� ����
        }
        return thickestBook;
    }

    void BookList::displayBooks() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "��������: " << current->book.title
                << ", �����: " << current->book.author
                << ", �������: " << current->book.pageCount << std::endl;
            current = current->next;
        }
    }
}