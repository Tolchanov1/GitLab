#include <iostream>
#include "lab4.h"

using namespace std;

namespace lab04 {

    // ����������� ������ DATE
    DATE::DATE(month mm, unsigned dd, unsigned yy) : mm(mm), dd(dd), yy(yy) {}

    // ����� ��� ������ ����
    void DATE::Print(char smb) {
        cout << (dd < 10 ? "0" : "") << dd << smb
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

    CompareDates::CompareDates(month mm, unsigned dd, unsigned yy) : DATE(mm, dd, yy) {}

    void CompareDates::Print(char smb) {
        DATE::Print(smb);
        cout << "��������� ���� ���������� �� ����������� �������." << endl;
    }

    unsigned CompareDates::Valid() {
        if (yy < 1) return 0;
        if (mm < jan || mm > dek) return 0;
        if (dd < 1 || dd > DaysInMonth()) return 0;
        return 1; // ���� ���������
    }

    unsigned CompareDates::SetDATE(unsigned dd, month mm, unsigned yy) {
        this->dd = dd;
        this->mm = mm;
        this->yy = yy;
        return Valid(); // ��������� ������������ ����� ����
    }

    int CompareDates::Compare(const CompareDates& other) const {
        if (yy != other.yy) return yy - other.yy;
        if (mm != other.mm) return mm - other.mm;
        return dd - other.dd;
    }

    int CompareDates::DaysDifference(const CompareDates& other) const {
        int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int totalDays1 = yy * 365 + dd;
        for (int m = 1; m < mm; ++m) {
            totalDays1 += daysInMonth[m];
        }

        // ��������� ���������� ����
        if (mm > 2 && (yy % 4 == 0) && (yy % 100 != 0 || yy % 400 == 0)) {
            totalDays1 += 1; // ���������� ���
        }

        int totalDays2 = other.yy * 365 + other.dd;
        for (int m = 1; m < other.mm; ++m) {
            totalDays2 += daysInMonth[m];
        }

        if (other.mm > 2 && (other.yy % 4 == 0) && (other.yy % 100 != 0 || other.yy % 400 == 0)) {
            totalDays2 += 1; // ���������� ���
        }

        return totalDays1 - totalDays2;
    }
}