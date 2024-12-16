#include <iostream>
#include "lab7_2.h"

using namespace std;

namespace lab07_2{

    void runDemo() {
        setlocale(LC_ALL, "RUS");

        Demo demo;

        while (true) {
            cout << "Выберите действие:" << endl;
            cout << "1 - Ввод значений" << endl;
            cout << "2 - Форматирование значений с помощью манипулятора" << endl;
            cout << "3 - Выход" << endl;
            cout << "Ваш выбор: ";

            int choice;

            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Некорректный ввод, введите действие еще раз." << endl;
                continue;
            }

            if (choice == 3) {
                cout << "Выход из программы." << endl;
                break;
            }
            else if (choice == 1) {
                // Ввод значений
                demo.inputValues();

                // Получение всех полей через tuple
                auto fields = demo.getFields();
                cout << "Значения через tuple: "
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

                cout << "Введите значение для float: ";
                while (!(cin >> f_num) || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Некорректный ввод! Введите вещественное число: ";
                }

                cout << "Введите значение для int: ";
                while (!(cin >> int_num) || cin.peek() != '\n') {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Некорректный ввод! Введите целое число: ";
                }

                cout << "Введите значение для char: ";
                while (true) {
                    string input;
                    cin >> input;

                    if (input.length() == 1) {
                        char_value = input[0];
                        break;
                    }
                    else {
                        cout << "Некорректный ввод! Введите один символ: ";
                    }
                }


                // Объекты манипуляторов
                Manip manip_float(3, 8, 16, '#'); // Точность, Ширина, Основание, Заполнение
                Manip manip_int(0, 10, 16, '*');
                Manip manip_char(0, 5, 10, '.');


                cout << "Результат с манипулятором для float: " << manip_float << f_num << endl;
                cout << "Результат с манипулятором для int: " << manip_int << int_num << endl;
                cout << "Результат с манипулятором для char: " << manip_char << char_value << endl;
            }
            else {
                cout << "Некорректный выбор. Попробуйте снова." << endl;
            }
        }

    }
}

// 1) Создать манипулятор (Класс Manip) и у него будут параметры (setw, setbase, setprecision, setfill) в порядке как в лабе
// 2) Если второе задание без классов, то создать класс demo в нем будут 5 переменных по варианту, 
// вызывать функцию GetFileds() с помощью которой получить все 5 элементов через tuple
// возвращаемое значение функции кортеж