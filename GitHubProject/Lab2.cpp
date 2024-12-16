#include "lab2.h"
#include <iostream>

namespace lab02 {

    // Конструктор книги
    Book::Book(const std::string& title, const std::string& author, int pageCount)
        : title(title), author(author), pageCount(pageCount) {}

    // Конструктор узла
    Node::Node(const Book& book) : book(book), next(nullptr) {}

    // Конструктор списка книг
    BookList::BookList() : head(nullptr) {}

    BookList::~BookList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;  // Сохраняем указатель на следующий узел
            delete current;                  // Удаляем текущий узел
            current = nextNode;              // Переходим к следующему узлу
        }
    }

    void BookList::addBook(const Book& book) {
        Node* newNode = new Node(book);
        newNode->next = head;               // Указываем следующий узел как текущую голову
        head = newNode;                     // Обновляем голову списка 
    }

    std::vector<Book*> BookList::findThickestBook() {
        std::vector<Book*> thickestBooks;
        if (head == nullptr) return thickestBooks;   // Если список пуст, возвращаем пустой вектор

        Node* current = head;
        int MaxPageCount = current->book.pageCount;  // Инициализируем максимальное количество страниц

        // Проходим по всему списку
        while (current != nullptr) {
            if (current->book.pageCount > MaxPageCount) {
                thickestBooks.clear(); // Очищаем вектор, если нашли более толстую книгу
                thickestBooks.push_back(&current->book);
                MaxPageCount = current->book.pageCount; // Обновляем максимальное количество страниц
            }
            else if (current->book.pageCount == MaxPageCount) {
                thickestBooks.push_back(&current->book); // Добавляем книгу, если она такая же толстая
            }
            current = current->next;                // Переход к следующему узлу
        }

        return thickestBooks;
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