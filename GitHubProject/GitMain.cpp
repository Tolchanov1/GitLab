#include <iostream>
#include <limits>
#include "lab1.h"
#include "lab2.h"
#include "lab3_a.h"
#include "lab3_b.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "Lab7.h"
#include "lab7_2.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	int choice;

	while (true) {
		cout << "�������� ����� ������������ ������: " << endl;
		cout << "1. ������������ ������ 1" << endl;
		cout << "2. ������������ ������ 2" << endl;
		cout << "3. ������������ ������ 3 (a)" << endl;
		cout << "4. ������������ ������ 3 (b)" << endl;
		cout << "5. ������������ ������ 4" << endl;
		cout << "6. ������������ ������ 5" << endl;
		cout << "7. ������������ ������ 6" << endl;
		cout << "8. ������������ ������ 7 (1)" << endl;
		cout << "9. ������������ ������ 7 (2)" << endl;

        cout << "����: ";
		cin >> choice;

		switch (choice) {
        case 1:
            lab01::runDemo();
            break;
        case 2:
            lab02::runDemo();
            break;
        case 3:
            lab03::runDemo();
            break;
        case 4:
            lab03_b::runDemo();
            break;
        case 5:
            lab04::runDemo();
            break;
        case 6:
            lab05::runDemo();
            break;
        case 7:
            lab06::runDemo();
            break;
        case 8:
            lab07::runDemo();
            break;
        case 9:
            lab07_2::runDemo();
        case 0:
            cout << "����� �� ���������.";
            return 0;
        default:
            std::cout << "������������ �����. ������� ����� ������������ ������ ��� ���" << endl;
		}
	}
}