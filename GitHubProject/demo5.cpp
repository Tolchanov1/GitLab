#include <iostream>
#include "lab5.h"

using namespace std;

namespace lab05{
    void runDemo() {

        setlocale(LC_ALL, "RUS");

        DateComparator compareDates;

        while (true) {
            unsigned day, year;
            int month_input;

            DATE date(jan, 1, 1); // ������������� ���� �� ���������

            // ���� ������ ���� � ���������
            while (true) {
                cout << "������� ������ ����: " << endl;
                cout << "������� �����: ";
                cin >> month_input;
                cout << "������� ����: ";
                cin >> day;
                cout << "������� ���: ";
                cin >> year;

                date = DATE(static_cast<month>(month_input), day, year);

                if (date.Valid()) {
                    break;
                }
                else {
                    cout << "������ ���� �����������. ����������, ������� �� ��� ���." << endl;
                }
            }

            DATE date2(jan, 1, 1); // ������������� ������ ���� �� ���������

            // ���� ������ ���� � ���������
            while (true) {
                cout << endl;
                cout << "������� ������ ����: " << endl;
                cout << "������� �����: ";
                cin >> month_input;
                cout << "������� ����: ";
                cin >> day;
                cout << "������� ���: ";
                cin >> year;

                date2 = DATE(static_cast<month>(month_input), day, year);

                if (date2.Valid()) {
                    break;
                }
                else {
                    cout << "������ ���� �����������. ����������, ������� �� ��� ���." << endl;
                }
            }

            cout << endl;
            cout << "������ ����: " << endl;
            cout << "������������ ������������� ����� Print()\n";
            date.Print('>');

            cout << endl;
            cout << "������ ����: " << endl;
            cout << "������������ ������������� ����� Print()\n";
            date2.Print();

            // ������������� �������������� ��������� ������
            cout << endl;
            cout << "������ ���� � ������� �������������� ��������� '<<': " << date << endl;
            cout << "������ ���� � ������� �������������� ��������� '<<': " << date2 << endl;

            // �������� � �������������� ���������
            cout << endl;
            cout << "�������� �� ��������� � ������� ���������:\n";
            if (compareDates(date, date2)) {
                cout << "������ ���� ����� ������ ����.\n";
            }
            else {
                cout << "������ ���� �� ����� ������ ����.\n";
            }

            // �������� ������������� ���������� ���������
            cout << endl;
            cout << "�������� �� ���������:\n";
            cout << "������������ ������������� �������� '=='\n";
            if (date == date2) {
                cout << "������ ���� ����� ������ ����.\n";
            }
            else {
                cout << "������ ���� �� ����� ������ ����.\n";
            }

            // ������������ ��������� ������������
            cout << endl;
            cout << "������������ ��������� ������������:\n";
            DATE date3 = date;
            cout << "date3 ����� ������������ ������ ����: " << date3 << endl;

            // ������������ ��������� �����������
            cout << endl;
            cout << "������������ ��������� �����������:\n";
            DATE date4 = move(date2);
            cout << "date4 ����� ����������� ������ ����: " << date4 << endl;
            cout << "������ ���� ����� �����������: " << date2 << endl;

            cout << endl;
            cout << "������ ��������� ������ ����? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice == 'N' || choice == 'n') {
                break;
            }
        }

    }
}