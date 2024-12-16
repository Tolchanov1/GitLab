#include <iostream>
#include "lab7.h"

namespace lab07 {

    // ����������� ������ DATE
    DATE::DATE(unsigned dd, month mm, unsigned yy) : dd(dd), mm(mm), yy(yy) {}

    // ����� ��� ������ ����
    void DATE::Print(char smb) {
        std::cout << (dd < 10 ? "0" : "") << dd << smb
            << (mm < 10 ? "0" : "") << mm << smb
            << yy << std::endl;
    }

    // ����� ��� �������� ������������ ����
    unsigned DATE::Valid() {
        if (yy < 1) return 0;
        if (mm < jan || mm > dek) return 0;
        if (dd < 1 || dd > DaysInMonth()) return 0;
        return 1;
    }

    // ����� ��� ����������� ���������� ���� � ������
    unsigned DATE::DaysInMonth() {
        switch (mm) {
        case feb: return (yy % 4 == 0 && (yy % 100 != 0 || yy % 400 == 0)) ? 29 : 28; // �������� �� ���������� ���
        case apr: case jun: case sep: case nov: return 30;
        default: return 31;
        }
    }

    // ����� ��� ��������� ����� ����
    unsigned DATE::SetDATE(unsigned dd, month mm, unsigned yy) {
        this->dd = dd;
        this->mm = mm;
        this->yy = yy;
        return Valid();
    }

    // ���������� ��������� ������ � ����� <<
    std::ostream& operator<<(std::ostream& os, const DATE& date) {
        os << (date.dd < 10 ? "0" : "") << date.dd << '/'
            << (date.mm < 10 ? "0" : "") << date.mm << '/'
            << date.yy;
        return os;
    }

    // ���������� ��������� ����� � �����
    std::istream& operator>>(std::istream& is, DATE& date) {
        unsigned day, year;
        int month_input;

        is >> day >> month_input >> year;
        date = DATE(day, static_cast<month>(month_input), year); // ���������� �����������
        return is;
    }
}