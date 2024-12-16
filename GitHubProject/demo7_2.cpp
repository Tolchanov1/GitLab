#include <iostream>
#include "lab7_2.h"

using namespace std;

namespace lab07_2{

    void runDemo() {
        setlocale(LC_ALL, "RUS");

        Demo demo;

        while (true) {
            cout << "�������� ��������:" << endl;
            cout << "1 - ���� ��������" << endl;
            cout << "2 - �������������� �������� � ������� ������������" << endl;
            cout << "3 - �����" << endl;
            cout << "��� �����: ";

            int choice;

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "������������ ����, ������� �������� ��� ���." << endl;
                continue;
            }

            if (choice == 3) {
                cout << "����� �� ���������." << endl;
                break;
            }
            else if (choice == 1) {
                // ���� ��������
                demo.inputValues();

                // ��������� ���� ����� ����� tuple
                auto fields = demo.getFields();
                cout << "�������� ����� tuple: "
                    << "f1 = " << get<0>(fields) << ", "
                    << "c = " << get<1>(fields) << ", "
                    << "i1 = " << get<2>(fields) << ", "
                    << "f2 = " << get<3>(fields) << ", "
                    << "i2 = " << get<4>(fields) << endl;

                demo.outputValues("output.txt");
            }
            else if (choice == 2) {
                float f_num;
                int int_num;
                char char_value;

                cout << "������� �������� ��� float: ";
                while (!(cin >> f_num) || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������������ ����! ������� ������������ �����: ";
                }

                cout << "������� �������� ��� int: ";
                while (!(cin >> int_num) || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "������������ ����! ������� ����� �����: ";
                }

                cout << "������� �������� ��� char: ";
                while (true) {
                    string input;
                    cin >> input;

                    if (input.length() == 1) {
                        char_value = input[0];
                        break;
                    }
                    else {
                        cout << "������������ ����! ������� ���� ������: ";
                    }
                }


                // ������� �������������
                Manip manip_float(3, 8, 16, '#'); // ��������, ������, ���������, ����������
                Manip manip_int(0, 10, 16, '*');
                Manip manip_char(0, 5, 10, '.');


                cout << "��������� � ������������� ��� float: " << manip_float << f_num << endl;
                cout << "��������� � ������������� ��� int: " << manip_int << int_num << endl;
                cout << "��������� � ������������� ��� char: " << manip_char << char_value << endl;
            }
            else {
                cout << "������������ �����. ���������� �����." << endl;
            }
        }

    }
}

// 1) ������� ����������� (����� Manip) � � ���� ����� ��������� (setw, setbase, setprecision, setfill) � ������� ��� � ����
// 2) ���� ������ ������� ��� �������, �� ������� ����� demo � ��� ����� 5 ���������� �� ��������, 
// �������� ������� GetFileds() � ������� ������� �������� ��� 5 ��������� ����� tuple
// ������������ �������� ������� ������