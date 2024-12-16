#include <iostream>
#include "lab1.h"

namespace lab01 {
    void runDemo() {

        setlocale(LC_ALL, "RUS");
        unsigned day, year;
        int month_input;
        char choice;

        do {
            std::cout << "�������� ��������: \n 1. �������� ���� �� ������������ \n 2. �������� ��� \n 3. ����� \n ����: ";
            std::cin >> choice;

            if (choice == '1') {
                // ���� ���� � ����������
                std::cout << "������� �����: ";
                std::cin >> month_input;
                std::cout << "������� ����: ";
                std::cin >> day;
                std::cout << "������� ���: ";
                std::cin >> year;

                DATE* date = (DATE*)malloc(sizeof(DATE)); // ��������� ������
                // *date = DATE(static_cast<month>(month_input), day, year);
                date->SetDayOfWeek(2);  // ��������� ��� ������

                //DATE date1(static_cast<month>(month_input), day, year);
                //DATE date2 = date1; // ������������� ������������ �����������

                // �������� � ����� ��������� ����
                std::cout << "��������� ����: ";
                date->Print('/');
                /* std::cout << "����� ���� ����� friend-�������: ";*/
                 //Print(date1);  // ����� friend-�������
                std::cout << "���� ������ (�����): " << date->GetDayOfWeek() << std::endl;
                std::cout << "��������� �� ����? " << (date->Valid() ? "��" : "���") << std::endl;

                free(date);

                //// ������� ����, ���� ��� ������� �����������
                //if (!date1.Valid()) {
                //    char answer;
                //    std::cout << "���� �����������. ������ �������� ����? (y/n): ";
                //    std::cin >> answer;

                //    if (answer == 'y' || answer == 'Y') {
                //        std::cout << "������� �����: ";
                //        std::cin >> month_input;
                //        std::cout << "������� ����: ";
                //        std::cin >> day;
                //        std::cout << "������� ���: ";
                //        std::cin >> year;

                //        // ��������� ����� ����
                //        date1.SetDATE(day, static_cast<month>(month_input), year);
                //        date1.Print('*');
                //        std::cout << "����� ���� ����� friend-�������: ";
                //        Print(date1);  // ����� friend-�������
                //        std::cout << "��������� �� ���� ������? " << (date1.Valid() ? "��" : "���") << std::endl;
                //    }
                //}
            }
            else if (choice == '2') {
                do {
                    unsigned day2, year2;
                    int month_input2;

                    std::cout << "������� ������ ����." << std::endl;
                    std::cout << "������� �����: ";
                    std::cin >> month_input;
                    std::cout << "������� ����: ";
                    std::cin >> day;
                    std::cout << "������� ���: ";
                    std::cin >> year;

                    DATE date1(static_cast<month>(month_input), day, year);

                    if (!date1.Valid()) {
                        std::cout << "������ ���� �����������. ������� ���� ������." << std::endl;
                        continue;
                    }

                    std::cout << "������� ������ ����." << std::endl;
                    std::cout << "������� �����: ";
                    std::cin >> month_input2;
                    std::cout << "������� ����: ";
                    std::cin >> day2;
                    std::cout << "������� ���: ";
                    std::cin >> year2;

                    DATE date2(static_cast<month>(month_input2), day2, year2);

                    if (!date2.Valid()) {
                        char answer;
                        std::cout << "������ ���� �����������. ������ �������� ����? (y/n): ";
                        std::cin >> answer;

                        if (answer == 'y' || answer == 'Y') {
                            std::cout << "������� �����: ";
                            std::cin >> month_input2;
                            std::cout << "������� ����: ";
                            std::cin >> day2;
                            std::cout << "������� ���: ";
                            std::cin >> year2;

                            date2.SetDATE(day2, static_cast<month>(month_input2), year2);
                        }
                        else {
                            continue;
                        }
                    }

                    DATE result = date1.AddDates(date2);

                    std::cout << "��������� ��������: ";
                    result.Print('/');
                    std::cout << "����� ���� ����� friend-�������: ";
                    Print(result);  // ����� friend-�������

                    std::cout << "��������� �� ��������� ����? " << (result.Valid() ? "��" : "���") << std::endl;

                    char answer;
                    std::cout << "������ ������� ���� ���? (y/n): ";
                    std::cin >> answer;

                    if (answer != 'y' && answer != 'Y') {
                        break;
                    }
                } while (true);
            }
            else if (choice == '3') {
                break;
            }
        } while (true);

    }
}