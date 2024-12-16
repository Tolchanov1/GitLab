#include <iostream>
#include "lab1.h"

namespace lab01 {
    void runDemo() {

        setlocale(LC_ALL, "RUS");
        unsigned day, year;
        int month_input;
        char choice;

        do {
            std::cout << "Выберите действие: \n 1. Проверка даты на корректность \n 2. Сложение дат \n 3. Выход \n Ввод: ";
            std::cin >> choice;

            if (choice == '1') {
                // Ввод даты с клавиатуры
                std::cout << "Введите месяц: ";
                std::cin >> month_input;
                std::cout << "Введите день: ";
                std::cin >> day;
                std::cout << "Введите год: ";
                std::cin >> year;

                DATE* date = (DATE*)malloc(sizeof(DATE)); // Выделение памяти
                // *date = DATE(static_cast<month>(month_input), day, year);
                date->SetDayOfWeek(2);  // Установка дня недели

                //DATE date1(static_cast<month>(month_input), day, year);
                //DATE date2 = date1; // Использование конструктора копирования

                // Проверка и вывод введенной даты
                std::cout << "Введенная дата: ";
                date->Print('/');
                /* std::cout << "Вывод даты через friend-функцию: ";*/
                 //Print(date1);  // Вызов friend-функции
                std::cout << "День недели (число): " << date->GetDayOfWeek() << std::endl;
                std::cout << "Корректна ли дата? " << (date->Valid() ? "Да" : "Нет") << std::endl;

                free(date);

                //// Измение даты, если она введена некорректно
                //if (!date1.Valid()) {
                //    char answer;
                //    std::cout << "Дата некорректна. Хотите изменить дату? (y/n): ";
                //    std::cin >> answer;

                //    if (answer == 'y' || answer == 'Y') {
                //        std::cout << "Введите месяц: ";
                //        std::cin >> month_input;
                //        std::cout << "Введите день: ";
                //        std::cin >> day;
                //        std::cout << "Введите год: ";
                //        std::cin >> year;

                //        // Установка новой даты
                //        date1.SetDATE(day, static_cast<month>(month_input), year);
                //        date1.Print('*');
                //        std::cout << "Вывод даты через friend-функцию: ";
                //        Print(date1);  // Вызов friend-функции
                //        std::cout << "Корректна ли дата сейчас? " << (date1.Valid() ? "Да" : "Нет") << std::endl;
                //    }
                //}
            }
            else if (choice == '2') {
                do {
                    unsigned day2, year2;
                    int month_input2;

                    std::cout << "Введите первую дату." << std::endl;
                    std::cout << "Введите месяц: ";
                    std::cin >> month_input;
                    std::cout << "Введите день: ";
                    std::cin >> day;
                    std::cout << "Введите год: ";
                    std::cin >> year;

                    DATE date1(static_cast<month>(month_input), day, year);

                    if (!date1.Valid()) {
                        std::cout << "Первая дата некорректна. Введите дату заново." << std::endl;
                        continue;
                    }

                    std::cout << "Введите вторую дату." << std::endl;
                    std::cout << "Введите месяц: ";
                    std::cin >> month_input2;
                    std::cout << "Введите день: ";
                    std::cin >> day2;
                    std::cout << "Введите год: ";
                    std::cin >> year2;

                    DATE date2(static_cast<month>(month_input2), day2, year2);

                    if (!date2.Valid()) {
                        char answer;
                        std::cout << "Вторая дата некорректна. Хотите изменить дату? (y/n): ";
                        std::cin >> answer;

                        if (answer == 'y' || answer == 'Y') {
                            std::cout << "Введите месяц: ";
                            std::cin >> month_input2;
                            std::cout << "Введите день: ";
                            std::cin >> day2;
                            std::cout << "Введите год: ";
                            std::cin >> year2;

                            date2.SetDATE(day2, static_cast<month>(month_input2), year2);
                        }
                        else {
                            continue;
                        }
                    }

                    DATE result = date1.AddDates(date2);

                    std::cout << "Результат сложения: ";
                    result.Print('/');
                    std::cout << "Вывод даты через friend-функцию: ";
                    Print(result);  // Вызов friend-функции

                    std::cout << "Корректна ли сложенная дата? " << (result.Valid() ? "Да" : "Нет") << std::endl;

                    char answer;
                    std::cout << "Хотите сложить даты еще? (y/n): ";
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