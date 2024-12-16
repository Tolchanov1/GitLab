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

            DATE date(jan, 1, 1); // Инициализация даты по умолчанию

            // Ввод первой даты с проверкой
            while (true) {
                cout << "Введите первую дату: " << endl;
                cout << "Введите месяц: ";
                cin >> month_input;
                cout << "Введите день: ";
                cin >> day;
                cout << "Введите год: ";
                cin >> year;

                date = DATE(static_cast<month>(month_input), day, year);

                if (date.Valid()) {
                    break;
                }
                else {
                    cout << "Первая дата некорректна. Пожалуйста, введите ее еще раз." << endl;
                }
            }

            DATE date2(jan, 1, 1); // Инициализация второй даты по умолчанию

            // Ввод второй даты с проверкой
            while (true) {
                cout << endl;
                cout << "Введите вторую дату: " << endl;
                cout << "Введите месяц: ";
                cin >> month_input;
                cout << "Введите день: ";
                cin >> day;
                cout << "Введите год: ";
                cin >> year;

                date2 = DATE(static_cast<month>(month_input), day, year);

                if (date2.Valid()) {
                    break;
                }
                else {
                    cout << "Вторая дата некорректна. Пожалуйста, введите ее еще раз." << endl;
                }
            }

            cout << endl;
            cout << "Первая дата: " << endl;
            cout << "Используется перегруженный метод Print()\n";
            date.Print('>');

            cout << endl;
            cout << "Вторая дата: " << endl;
            cout << "Используется перегруженный метод Print()\n";
            date2.Print();

            // Использование перегруженного оператора вывода
            cout << endl;
            cout << "Первая дата с помощью перегруженного оператора '<<': " << date << endl;
            cout << "Вторая дата с помощью перегруженного оператора '<<': " << date2 << endl;

            // Проверка с использованием функторов
            cout << endl;
            cout << "Проверка на равенство с помощью функторов:\n";
            if (compareDates(date, date2)) {
                cout << "Первая дата равна второй дате.\n";
            }
            else {
                cout << "Первая дата не равна второй дате.\n";
            }

            // Проверка перегруженным оператором сравнения
            cout << endl;
            cout << "Проверка на равенство:\n";
            cout << "Используется перегруженный оператор '=='\n";
            if (date == date2) {
                cout << "Первая дата равна второй дате.\n";
            }
            else {
                cout << "Первая дата не равна второй дате.\n";
            }

            // Демонстрация оператора присваивания
            cout << endl;
            cout << "Демонстрация оператора присваивания:\n";
            DATE date3 = date;
            cout << "date3 после присваивания первой даты: " << date3 << endl;

            // Демонстрация оператора перемещения
            cout << endl;
            cout << "Демонстрация оператора перемещения:\n";
            DATE date4 = move(date2);
            cout << "date4 после перемещения второй даты: " << date4 << endl;
            cout << "Вторая дата после перемещения: " << date2 << endl;

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