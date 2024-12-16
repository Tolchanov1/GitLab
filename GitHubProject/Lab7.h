#pragma once

namespace lab07 {
    void runDemo();

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    class DATE {
    public:
        DATE(unsigned dd, month mm, unsigned yy); // Конструктор

        void Print(char smb); // Метод для вывода даты
        unsigned Valid(); // Метод для проверки корректности даты
        unsigned SetDATE(unsigned dd, month mm, unsigned yy); // Метод для изменения даты

        friend std::ostream& operator<<(std::ostream& os, const DATE& date); // Оператор вывода
        friend std::istream& operator>>(std::istream& is, DATE& date); // Оператор ввода

    private:
        unsigned dd;
        month mm;
        unsigned yy;

        unsigned DaysInMonth(); // Метод для определения количества дней в месяце
    };
}