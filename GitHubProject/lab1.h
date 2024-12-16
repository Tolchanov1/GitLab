#pragma once

namespace lab01 {
    void runDemo();

        enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

        class DATE {
        public:
            DATE(month mm, unsigned dd, unsigned yy);      // �����������
            DATE(const DATE& other);                       // ����������� �����������
            ~DATE();                                       // ����������
            void Print(char smb);                         // ����� ��� ������ ����
            unsigned Valid();                             // ����� ��� �������� ������������ ����
            unsigned SetDATE(unsigned dd, month mm, unsigned yy); // ����� ��� ��������� ����
            void SetDayOfWeek(int num);                    // ������ ��� ��������� ��� ������
            int GetDayOfWeek();                   // ������ ��� ��������� ��� ������


            // Inline ����� ��� �������� ���
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

            // Friend ������� ��� ������ ����
            friend void Print(const DATE& date);

        private:
            unsigned dd;
            month mm;
            unsigned yy;
            int* day_of_week;

            unsigned DaysInMonth();                       // ����� ��� ����������� ���������� ���� � ������
        };
}