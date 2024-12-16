#pragma once

namespace lab07 {
    void runDemo();

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    class DATE {
    public:
        DATE(unsigned dd, month mm, unsigned yy); // �����������

        void Print(char smb); // ����� ��� ������ ����
        unsigned Valid(); // ����� ��� �������� ������������ ����
        unsigned SetDATE(unsigned dd, month mm, unsigned yy); // ����� ��� ��������� ����

        friend std::ostream& operator<<(std::ostream& os, const DATE& date); // �������� ������
        friend std::istream& operator>>(std::istream& is, DATE& date); // �������� �����

    private:
        unsigned dd;
        month mm;
        unsigned yy;

        unsigned DaysInMonth(); // ����� ��� ����������� ���������� ���� � ������
    };
}