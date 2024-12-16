#pragma once

namespace lab05 {
    void runDemo();

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    class DATE {
    public:
        DATE(month mm, unsigned dd, unsigned yy); // Конструктор
        DATE(const DATE& other); // Конструктор копирования

        DATE& operator=(const DATE& other); // Оператор присваивания
        DATE& operator=(DATE&& other) noexcept; // Оператор перемещения

        void Print(char smb); // Метод для вывода даты
        void Print(); // Перегруженный метод для вывода даты в стандартном формате
        unsigned Valid(); // Метод для проверки корректности даты
        unsigned SetDATE(unsigned dd, month mm, unsigned yy); // Метод для изменения даты

        // Доступ к приватным членам для перегрузки операторов
        unsigned getDay() const { return dd; }
        month getMonth() const { return mm; }
        unsigned getYear() const { return yy; }
        friend std::ostream& operator<<(std::ostream& os, const DATE& date);
        friend std::istream& operator>>(std::istream& is, DATE& date); // Оператор ввода
        bool operator==(const DATE& rhs);

    private:
        unsigned dd;
        month mm;
        unsigned yy;

        unsigned DaysInMonth(); // Метод для определения количества дней в месяце
    };

    class DateComparator {
    public:
        bool operator()(const DATE& date1, const DATE& date2);
    };
}