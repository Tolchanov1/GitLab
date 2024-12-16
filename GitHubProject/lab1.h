#pragma once

namespace lab01 {
    void runDemo();

        enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

        class DATE {
        public:
            DATE(month mm, unsigned dd, unsigned yy);      // Конструктор
            DATE(const DATE& other);                       // Конструктор копирования
            ~DATE();                                       // Деструктор
            void Print(char smb);                         // Метод для вывода даты
            unsigned Valid();                             // Метод для проверки корректности даты
            unsigned SetDATE(unsigned dd, month mm, unsigned yy); // Метод для изменения даты
            void SetDayOfWeek(int num);                    // Сеттер для установки дня недели
            int GetDayOfWeek();                   // Геттер для получения дня недели


            // Inline метод для сложения дат
            inline DATE AddDates(const DATE& other) {
                unsigned new_dd = dd + other.dd;
                unsigned new_mm = mm + other.mm;
                unsigned new_yy = yy + other.yy;

                if (new_dd > DaysInMonth()) {
                    new_dd -= DaysInMonth();
                    new_mm++;
                }

                if (new_mm > 12) {
                    new_mm -= 12;
                    new_yy++;
                }

                return DATE(static_cast<month>(new_mm), new_dd, new_yy);
            }

            // Friend функция для вывода даты
            friend void Print(const DATE& date);

        private:
            unsigned dd;
            month mm;
            unsigned yy;
            int* day_of_week;

            unsigned DaysInMonth();                       // Метод для определения количества дней в месяце
        };
}