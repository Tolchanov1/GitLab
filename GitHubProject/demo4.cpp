#include <iostream>
#include "lab4.h"

using namespace std;

namespace lab04 {
    void runDemo(){

        setlocale(LC_ALL, "RUS");
        unsigned day, year;
        int month_input;
        char choice;

        do {
            cout << "�������� ��������: \n1. �������� ���� �� ������������ \n2. ��������� ��� \n3. ����� \n����: ";
            cin >> choice;
            cout << endl;

            if (choice == '1') {
                // ���� ���� � ����������
                cout << "������� �����: ";
                cin >> month_input;
                cout << "������� ����: ";
                cin >> day;
                cout << "������� ���: ";
                cin >> year;

                CompareDates date1(static_cast<month>(month_input), day, year);

                // �������� � ����� ��������� ����
                cout << "��������� ����: ";
                date1.Print('.');
                cout << "��������� �� ����? " << (date1.Valid() ? "��" : "���") << endl;
                cout << endl;

                // ������� ����, ���� ��� ������� �����������
                if (!date1.Valid()) {
                    char answer;
                    cout << "���� �����������. ������ �������� ����? (y/n): ";
                    cin >> answer;

                    if (answer == 'y' || answer == 'Y') {
                        cout << "������� �����: ";
                        cin >> month_input;
                        cout << "������� ����: ";
                        cin >> day;
                        cout << "������� ���: ";
                        cin >> year;

                        // ��������� ����� ����
                        date1.SetDATE(day, static_cast<month>(month_input), year);
                        date1.Print('.');
                        cout << "��������� �� ���� ������? " << (date1.Valid() ? "��" : "���") << endl;
                        cout << endl;
                    }
                }
            }
            else if (choice == '2') {
                CompareDates date1(static_cast<month>(0), 0, 0);
                CompareDates date2(static_cast<month>(0), 0, 0);

                while (true) {
                    cout << "������� ������ ����:\n";
                    cout << "������� �����: ";
                    cin >> month_input;
                    cout << "������� ����: ";
                    cin >> day;
                    cout << "������� ���: ";
                    cin >> year;
                    cout << endl;

                    CompareDates date1(static_cast<month>(month_input), day, year);
                    if (!date1.Valid()) {
                        cout << "������ ���� �����������. ���������� �����." << endl;
                        continue; // ������������ � ������ �����
                    }

                    cout << "������� ������ ����:\n";
                    cout << "������� �����: ";
                    cin >> month_input;
                    cout << "������� ����: ";
                    cin >> day;
                    cout << "������� ���: ";
                    cin >> year;
                    cout << endl;

                    CompareDates date2(static_cast<month>(month_input), day, year);
                    if (!date2.Valid()) {
                        cout << "������ ���� �����������. ���������� �����." << endl;
                        continue; // ������������ � ������ �����
                    }

                    int comparison = date1.Compare(date2);
                    if (comparison < 0) {
                        cout << "������ ���� ������ ������." << endl;
                    }
                    else if (comparison > 0) {
                        cout << "������ ���� ����� ������." << endl;
                    }
                    else {
                        cout << "���� �����." << endl;
                    }

                    int difference = date1.DaysDifference(date2);
                    cout << "������� � ����: " << abs(difference) << endl;
                    cout << endl;
                    break;
                }
            }
            else if (choice == '3') {
                break;
            }
        } while (true);
    }
}