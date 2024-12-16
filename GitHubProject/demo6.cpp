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
            int leastFrequent[7]; // ������ ��� �������� �������� ����� ������������� �����
            int count = 0;

            intCounter.print("������� ����� ����� (0, 1, 2, 3, 4, 5, 6; ��� ���������� ������� 'q'):");
            while (true) {
                cin.getline(input, 256);

                if (input[0] == 'q' && input[1] == '\0') break;

                try {
                    int number = atoi(input);
                    if (isValidInteger(number)) {
                        intCounter.addData(number);
                    }
                    else {
                        intCounter.print("������� ������������ �����.");
                    }
                }
                catch (const invalid_argument&) {
                    intCounter.print("����������, ������� ���������� ����� ����� ��� 'q' ��� ������.");
                }
            }
            intCounter.findLeastFrequent(leastFrequent, count);
            intCounter.print("�������� ����� ������������� ����� �����: ");
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

            charCounter.print("������� ������� ('0', '1', '2', 'A', 'B', 'C', 'D'; ��� ���������� ������� 'q'):");
            while (true) {
                cin.getline(input, 256);

                if (input[0] == 'q' && input[1] == '\0') break;

                if (input[1] == '\0' && isValidChar(input[0])) {
                    charCounter.addData(input[0]);
                }
                else {
                    charCounter.print("������� ������������ �����");
                }
            }
            charCounter.findLeastFrequent(leastFrequent, count);
            charCounter.print("�������� ����� ������������� �������: ");
            for (int i = 0; i < count; i++) {
                cout << leastFrequent[i] << " ";
            }
            cout << endl;
        }
        
        void runDemo(){
        setlocale(LC_ALL, "RUS");
        char option;

        do {
            cout << "�������� ��� ������ ��� �������� �� �������: \n(1) ����� ����� \n(2) ������� \n(q) ����� \n����: ";
            cin >> option;
            cin.ignore(); // ������� ������ ����� �����

            switch (option) {
            case '1':
                findLeastFrequentIntegers();
                break;
            case '2':
                findLeastFrequentChars();
                break;
            case 'q':
                cout << "����� �� ���������." << endl;
                break;
            default:
                cout << "�������� �����, ���������� �����." << endl;
            }
        } while (option != 'q');

    }
}