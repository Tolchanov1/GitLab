#include "lab3_a.h"
#include <iostream>

namespace lab03 {

    Book::Book(const std::string& title, const std::string& author, int pageCount)
        : title(title), author(author), pageCount(pageCount) {}

    Node::Node(const Book& book) : book(book), next(nullptr) {}

    BookList::BookList() : head(nullptr) {}

    BookList::~BookList() {
        while (head != nullptr) {
            Node* nextNode = head->next;  // Сохраняем указатель на следующий узел
            delete head;                  // Удаляем текущий узел
            head = nextNode;              // Переходим к следующему узлу
        }
    }

    void BookList::addBook(const Book& book) {
        Node* newNode = new Node(book);  // Создаем новый узел
        newNode->next = head;             // Указываем следующий узел как текущую голову
        head = newNode;                   // Обновляем голову списка 
    }

    Book* BookList::findThickestBook() {
        if (head == nullptr) return nullptr;

        Node* current = head;
        Book* thickestBook = &current->book; // Инициализируем самую толстую книгу первой книгой

        // Проходим по всему списку
        while (current != nullptr) {
            if (current->book.pageCount > thickestBook->pageCount) {
                thickestBook = &current->book; // Обновляем самую толстую книгу
            }
            current = current->next;            // Переход к следующему узлу
        }
        return thickestBook;
    }

    void BookList::displayBooks() const {
        Node* current = head;
        while (current != nullptr) {
            std::cout << "Название: " << current->book.title
                << ", Автор: " << current->book.author
                << ", Страниц: " << current->book.pageCount << std::endl;
            current = current->next;
        }
    }
}