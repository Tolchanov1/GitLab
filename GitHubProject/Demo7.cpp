#include <iostream>
#include "lab7.h"

using namespace std;

namespace lab07 {

    // Функция для проверки ввода чисел
    bool CheckInput(istream& is) {
        if (is.fail()) { // Если ввод некорректный
            is.clear();  // Сбрасываем флаг ошибки
            is.ignore(numeric_limits<streamsize>::max(), '\n'); // Очищаем ввод
            return false;
        }
        return true;
    }

    void runDemo() {
        setlocale(LC_ALL, "RUS");

        while (true) {
            unsigned day, year;
            int month_input;

            DATE date(1, jan, 1); // Инициализация даты по умолчанию

            // Ввод первой даты с проверкой
            while (true) {
                cout << "Введите первую дату через пробел (ДД ММ ГГГГ): ";
                cin >> date;

                if (!CheckInput(cin)) {
                    cout << "Ошибка: допускаются только числа." << endl;
                    continue;
                }

                if (date.Valid()) {
                    break;
                }
                else {
                    cout << "Первая дата некорректна. Пожалуйста, введите ее еще раз." << endl;
                }
            }

            DATE date2(1, jan, 1); // Инициализация второй даты по умолчанию

            // Ввод второй даты с проверкой
            while (true) {
                cout << endl;
                cout << "Введите вторую дату через пробел (ДД ММ ГГГГ): ";
                cin >> date2;

                if (!CheckInput(cin)) {
                    cout << "Ошибка: допускаются только числа." << endl;
                    continue;
                }

                if (date2.Valid()) {
                    break;
                }
                else {
                    cout << "Вторая дата некорректна. Пожалуйста, введите ее еще раз." << endl;
                }
            }

            cout << endl;
            cout << "Первая дата с помощью переопределенной операции '<<': " << date << endl;
            cout << "Вторая дата с помощью переопределенной операции '<<': " << date2 << endl;

            cout << endl;
            cout << "Хотите проверить другие даты? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice == 'N' || choice == 'n') {
                break;
            }
        }

    }
}