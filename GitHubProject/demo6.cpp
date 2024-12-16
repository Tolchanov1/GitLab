#include "lab6.h"
#include <iostream>

using namespace std;

namespace lab06 {

        bool isValidInteger(int number) {
            return number >= 0 && number <= 6;
        }

        bool isValidChar(char character) {
            return character == '0' || character == '1' || character == '2' || character == 'A' || character == 'B' || character == 'C' || character == 'D';
        }


        void findLeastFrequentIntegers() {
            FrequencyCounter<int> intCounter;
            char input[256];
            int leastFrequent[7]; // Массив для хранения наименее часто встречающихся чисел
            int count = 0;

            intCounter.print("Введите целые числа (0, 1, 2, 3, 4, 5, 6; для завершения введите 'q'):");
            while (true) {
                cin.getline(input, 256);

                if (input[0] == 'q' && input[1] == '\0') break;

                try {
                    int number = atoi(input);
                    if (isValidInteger(number)) {
                        intCounter.addData(number);
                    }
                    else {
                        intCounter.print("Введено недопустимое число.");
                    }
                }
                catch (const invalid_argument&) {
                    intCounter.print("Пожалуйста, введите корректное целое число или 'q' для выхода.");
                }
            }
            intCounter.findLeastFrequent(leastFrequent, count);
            intCounter.print("Наиболее редко встречающееся целые числа: ");
            for (int i = 0; i < count; i++) {
                cout << leastFrequent[i] << " ";
            }
            cout << endl;
        }

        void findLeastFrequentChars() {
            FrequencyCounter<char> charCounter;
            char input[256];
            char leastFrequent[7];
            int count = 0;

            charCounter.print("Введите символы ('0', '1', '2', 'A', 'B', 'C', 'D'; для завершения введите 'q'):");
            while (true) {
                cin.getline(input, 256);

                if (input[0] == 'q' && input[1] == '\0') break;

                if (input[1] == '\0' && isValidChar(input[0])) {
                    charCounter.addData(input[0]);
                }
                else {
                    charCounter.print("Введено недопустимое число");
                }
            }
            charCounter.findLeastFrequent(leastFrequent, count);
            charCounter.print("Наиболее редко встречающиеся символы: ");
            for (int i = 0; i < count; i++) {
                cout << leastFrequent[i] << " ";
            }
            cout << endl;
        }
        
        void runDemo(){
        setlocale(LC_ALL, "RUS");
        char option;

        do {
            cout << "Выберите тип данных для проверки на частоту: \n(1) Целые числа \n(2) Символы \n(q) Выход \nВвод: ";
            cin >> option;
            cin.ignore(); // Очистка буфера после ввода

            switch (option) {
            case '1':
                findLeastFrequentIntegers();
                break;
            case '2':
                findLeastFrequentChars();
                break;
            case 'q':
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор, попробуйте снова." << endl;
            }
        } while (option != 'q');

    }
}