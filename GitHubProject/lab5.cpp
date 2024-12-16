#include <iostream>
#include "lab5.h"

namespace lab05 {

    // Конструктор класса DATE
    DATE::DATE(month mm, unsigned dd, unsigned yy) : mm(mm), dd(dd), yy(yy) {}

    // Конструктор копирования
    DATE::DATE(const DATE& other) : mm(other.mm), dd(other.dd), yy(other.yy) {}

    // Оператор присваивания
    DATE& DATE::operator=(const DATE& other) {
        if (this != &other) {
            this->dd = other.dd;
            this->mm = other.mm;
            this->yy = other.yy;
        }
        return *this;
    }

    // Оператор перемещения
    DATE& DATE::operator=(DATE&& other) noexcept {
        if (this != &other) {
            this->dd = other.dd;
            this->mm = other.mm;
            this->yy = other.yy;

            other.dd = 0;
            other.mm = jan;
            other.yy = 0;
        }
        return *this;
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
        this->dd = dd;
        this->mm = mm;
        this->yy = yy;
        return Valid();
    }

    // Перегруженный метод для вывода даты в стандартном формате (дд.мм.гггг)
    void DATE::Print() {
        std::cout << (dd < 10 ? "0" : "") << dd << '.'
            << (mm < 10 ? "0" : "") << mm << '.'
            << yy << std::endl;
    }

    // Перегрузка оператора сравнения ==
    bool DATE::operator==(const DATE& rhs) {
        return this->getDay() == rhs.getDay() && this->getMonth() == rhs.getMonth() && this->getYear() == rhs.getYear();
    }

    // Перегрузка оператора вывода в поток <<
    std::ostream& operator<<(std::ostream& os, const DATE& date) {
        os << (date.getDay() < 10 ? "0" : "") << date.getDay() << '/'
            << (date.getMonth() < 10 ? "0" : "") << date.getMonth() << '/'
            << date.getYear();
        return os;
    }

    // Перегрузка оператора ввода в поток
    std::istream& operator>>(std::istream& is, DATE& date) {
        unsigned day, year;
        int month_input;

        is >> month_input >> day >> year;
        date = DATE(static_cast<month>(month_input), day, year); // Используем конструктор
        return is;
    }

    // Перегрузка функтора по сравнению двух дат
    bool DateComparator::operator()(const DATE& date1, const DATE& date2) {
        return date1.getYear() == date2.getYear() &&
            date1.getMonth() == date2.getMonth() &&
            date1.getDay() == date2.getDay();
    }
}