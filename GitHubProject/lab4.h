#pragma once

namespace lab04 {
    void runDemo();

    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    class DATE {
    public:
        virtual void Print(char smb); // ����� ��� ������ ����
        virtual unsigned Valid(); // ����� ��� �������� ������������ ����
        virtual unsigned SetDATE(unsigned dd, month mm, unsigned yy); // ����� ��� ��������� ����

    protected:
        DATE(month mm, unsigned dd, unsigned yy); // �����������
        unsigned dd;
        month mm;
        unsigned yy;
        unsigned DaysInMonth(); // ����� ��� ����������� ���������� ���� � ������

    };

    class CompareDates : public DATE {
    public:
        CompareDates(month mm, unsigned dd, unsigned yy);

        void Print(char smb) override;
        unsigned Valid() override;
        unsigned SetDATE(unsigned dd, month mm, unsigned yy) override;

        int Compare(const CompareDates& other) const;
        int DaysDifference(const CompareDates& other) const;
    };
}