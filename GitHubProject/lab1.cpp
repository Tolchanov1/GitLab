#include <iostream>
#include "lab1.h"

namespace lab01 {

    // Конструктор класса DATE
    DATE::DATE(month mm, unsigned dd, unsigned yy) : mm(mm), dd(dd), yy(yy) {
        day_of_week = (int*)malloc(sizeof(int));
        std::cout << "Вызвался обычный конструктор для объекта " << this << std::endl;
    }

    // Конструктор копирования
    DATE::DATE(const DATE& other) : dd(other.dd), mm(other.mm), yy(other.yy) {

        std::cout << "Вызвался конструктор копирования для объекта " << this << std::endl;
    }

    // Деструктор
    DATE::~DATE() {
        free(day_of_week);
        std::cout << "Вызвался деструктор для объекта " << this << std::endl;
    }

    // Метод для вывода даты
    void DATE::Print(char smb) {
        std::cout << (dd < 10 ? "0" : "") << dd << smb
            << (mm < 10 ? "0" : "") << mm << smb
            << yy << std::endl;
    }

    // Метод для проверки корректности даты
    unsigned DATE::Valid() {
        if (yy < 1) return 0;
        if (mm < jan || mm > dek) return 0;
        if (dd < 1 || dd > DaysInMonth()) return 0;
        return 1;
    }

    // Метод для определения количества дней в месяце
    unsigned DATE::DaysInMonth() {
        switch (mm) {
        case feb: return (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0)) ? 29 : 28; // Проверка на високосный год
        case apr: case jun: case sep: case nov: return 30;
        default: return 31;
        }
    }

    // Метод для установки новой даты
    unsigned DATE::SetDATE(unsigned dd, month mm, unsigned yy) {
        if (yy < 1 || mm < jan || mm > dek) return 0;
        if (dd < 1 || dd > DaysInMonth()) return 0;

        this->dd = dd;
        this->mm = mm;
        this->yy = yy;
        return 1;
    }

    // Friend функция для вывода даты
    void Print(const DATE& date) {
        std::cout << (date.dd < 10 ? "0" : "") << date.dd << '/'
            << (date.mm < 10 ? "0" : "") << date.mm << '/'
            << date.yy << std::endl;
    }

    void DATE::SetDayOfWeek(int num) {
        if (num < 0 || num>6) {
            std::cerr << "Некорректный номер дня недели." << std::endl;
            return;
        }
        *day_of_week = num;
    }

    int DATE::GetDayOfWeek() {
        return *day_of_week;
    }
}