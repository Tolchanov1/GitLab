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
            cout << "Выберите действие: \n1. Проверка даты на корректность \n2. Сравнение дат \n3. Выход \nВвод: ";
            cin >> choice;
            cout << endl;

            if (choice == '1') {
                // Ввод даты с клавиатуры
                cout << "Введите месяц: ";
                cin >> month_input;
                cout << "Введите день: ";
                cin >> day;
                cout << "Введите год: ";
                cin >> year;

                CompareDates date1(static_cast<month>(month_input), day, year);

                // Проверка и вывод введенной даты
                cout << "Введенная дата: ";
                date1.Print('.');
                cout << "Корректна ли дата? " << (date1.Valid() ? "Да" : "Нет") << endl;
                cout << endl;

                // Измение даты, если она введена некорректно
                if (!date1.Valid()) {
                    char answer;
                    cout << "Дата некорректна. Хотите изменить дату? (y/n): ";
                    cin >> answer;

                    if (answer == 'y' || answer == 'Y') {
                        cout << "Введите месяц: ";
                        cin >> month_input;
                        cout << "Введите день: ";
                        cin >> day;
                        cout << "Введите год: ";
                        cin >> year;

                        // Установка новой даты
                        date1.SetDATE(day, static_cast<month>(month_input), year);
                        date1.Print('.');
                        cout << "Корректна ли дата сейчас? " << (date1.Valid() ? "Да" : "Нет") << endl;
                        cout << endl;
                    }
                }
            }
            else if (choice == '2') {
                CompareDates date1(static_cast<month>(0), 0, 0);
                CompareDates date2(static_cast<month>(0), 0, 0);

                while (true) {
                    cout << "Введите первую дату:\n";
                    cout << "Введите месяц: ";
                    cin >> month_input;
                    cout << "Введите день: ";
                    cin >> day;
                    cout << "Введите год: ";
                    cin >> year;
                    cout << endl;

                    CompareDates date1(static_cast<month>(month_input), day, year);
                    if (!date1.Valid()) {
                        cout << "Первая дата некорректна. Попробуйте снова." << endl;
                        continue; // Возвращаемся к началу цикла
                    }

                    cout << "Введите вторую дату:\n";
                    cout << "Введите месяц: ";
                    cin >> month_input;
                    cout << "Введите день: ";
                    cin >> day;
                    cout << "Введите год: ";
                    cin >> year;
                    cout << endl;

                    CompareDates date2(static_cast<month>(month_input), day, year);
                    if (!date2.Valid()) {
                        cout << "Вторая дата некорректна. Попробуйте снова." << endl;
                        continue; // Возвращаемся к началу цикла
                    }

                    int comparison = date1.Compare(date2);
                    if (comparison < 0) {
                        cout << "Первая дата раньше второй." << endl;
                    }
                    else if (comparison > 0) {
                        cout << "Первая дата позже второй." << endl;
                    }
                    else {
                        cout << "Даты равны." << endl;
                    }

                    int difference = date1.DaysDifference(date2);
                    cout << "Разница в днях: " << abs(difference) << endl;
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