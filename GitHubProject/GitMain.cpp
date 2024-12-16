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
		cout << "Выберите номер лабораторной работы: " << endl;
		cout << "1. Лабораторная работа 1" << endl;
		cout << "2. Лабораторная работа 2" << endl;
		cout << "3. Лабораторная работа 3 (a)" << endl;
		cout << "4. Лабораторная работа 3 (b)" << endl;
		cout << "5. Лабораторная работа 4" << endl;
		cout << "6. Лабораторная работа 5" << endl;
		cout << "7. Лабораторная работа 6" << endl;
		cout << "8. Лабораторная работа 7 (1)" << endl;
		cout << "9. Лабораторная работа 7 (2)" << endl;

        cout << "Ввод: ";
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
            cout << "Выход из программы.";
            return 0;
        default:
            std::cout << "Некорректный выбор. Введите номер лабораторной работы еще раз" << endl;
		}
	}
}