#include <iostream>
#include "lab7.h"

using namespace std;

namespace lab07 {

    // ������� ��� �������� ����� �����
    bool CheckInput(istream& is) {
        if (is.fail()) { // ���� ���� ������������
            is.clear();  // ���������� ���� ������
            is.ignore(numeric_limits<streamsize>::max(), '\n'); // ������� ����
            return false;
        }
        return true;
    }

    void runDemo() {
        setlocale(LC_ALL, "RUS");

        while (true) {
            unsigned day, year;
            int month_input;

            DATE date(1, jan, 1); // ������������� ���� �� ���������

            // ���� ������ ���� � ���������
            while (true) {
                cout << "������� ������ ���� ����� ������ (�� �� ����): ";
                cin >> date;

                if (!CheckInput(cin)) {
                    cout << "������: ����������� ������ �����." << endl;
                    continue;
                }

                if (date.Valid()) {
                    break;
                }
                else {
                    cout << "������ ���� �����������. ����������, ������� �� ��� ���." << endl;
                }
            }

            DATE date2(1, jan, 1); // ������������� ������ ���� �� ���������

            // ���� ������ ���� � ���������
            while (true) {
                cout << endl;
                cout << "������� ������ ���� ����� ������ (�� �� ����): ";
                cin >> date2;

                if (!CheckInput(cin)) {
                    cout << "������: ����������� ������ �����." << endl;
                    continue;
                }

                if (date2.Valid()) {
                    break;
                }
                else {
                    cout << "������ ���� �����������. ����������, ������� �� ��� ���." << endl;
                }
            }

            cout << endl;
            cout << "������ ���� � ������� ���������������� �������� '<<': " << date << endl;
            cout << "������ ���� � ������� ���������������� �������� '<<': " << date2 << endl;

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