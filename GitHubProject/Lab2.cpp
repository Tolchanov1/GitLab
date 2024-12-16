#include "lab2.h"
#include <iostream>

namespace lab02 {

    // ����������� �����
    Book::Book(const std::string& title, const std::string& author, int pageCount)
        : title(title), author(author), pageCount(pageCount) {}

    // ����������� ����
    Node::Node(const Book& book) : book(book), next(nullptr) {}

    // ����������� ������ ����
    BookList::BookList() : head(nullptr) {}

    BookList::~BookList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;  // ��������� ��������� �� ��������� ����
            delete current;                  // ������� ������� ����
            current = nextNode;              // ��������� � ���������� ����
        }
    }

    void BookList::addBook(const Book& book) {
        Node* newNode = new Node(book);
        newNode->next = head;               // ��������� ��������� ���� ��� ������� ������
        head = newNode;                     // ��������� ������ ������ 
    }

    std::vector<Book*> BookList::findThickestBook() {
        std::vector<Book*> thickestBooks;
        if (head == nullptr) return thickestBooks;   // ���� ������ ����, ���������� ������ ������

        Node* current = head;
        int MaxPageCount = current->book.pageCount;  // �������������� ������������ ���������� �������

        // �������� �� ����� ������
        while (current != nullptr) {
            if (current->book.pageCount > MaxPageCount) {
                thickestBooks.clear(); // ������� ������, ���� ����� ����� ������� �����
                thickestBooks.push_back(&current->book);
                MaxPageCount = current->book.pageCount; // ��������� ������������ ���������� �������
            }
            else if (current->book.pageCount == MaxPageCount) {
                thickestBooks.push_back(&current->book); // ��������� �����, ���� ��� ����� �� �������
            }
            current = current->next;                // ������� � ���������� ����
        }

        return thickestBooks;
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