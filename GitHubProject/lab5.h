#pragma once

namespace lab05 {
    void runDemo();

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    class DATE {
    public:
        DATE(month mm, unsigned dd, unsigned yy); // �����������
        DATE(const DATE& other); // ����������� �����������

        DATE& operator=(const DATE& other); // �������� ������������
        DATE& operator=(DATE&& other) noexcept; // �������� �����������

        void Print(char smb); // ����� ��� ������ ����
        void Print(); // ������������� ����� ��� ������ ���� � ����������� �������
        unsigned Valid(); // ����� ��� �������� ������������ ����
        unsigned SetDATE(unsigned dd, month mm, unsigned yy); // ����� ��� ��������� ����

        // ������ � ��������� ������ ��� ���������� ����������
        unsigned getDay() const { return dd; }
        month getMonth() const { return mm; }
        unsigned getYear() const { return yy; }
        friend std::ostream& operator<<(std::ostream& os, const DATE& date);
        friend std::istream& operator>>(std::istream& is, DATE& date); // �������� �����
        bool operator==(const DATE& rhs);

    private:
        unsigned dd;
        month mm;
        unsigned yy;

        unsigned DaysInMonth(); // ����� ��� ����������� ���������� ���� � ������
    };

    class DateComparator {
    public:
        bool operator()(const DATE& date1, const DATE& date2);
    };
}