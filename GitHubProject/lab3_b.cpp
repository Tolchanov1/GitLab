#include "lab3_b.h"
#include <limits>

using namespace std;

namespace lab03_b {

    CharArray::CharArray(size_t n) : size(n), validCount(0) {
        arr = new char[size];
    }

    CharArray::~CharArray() {
        delete[] arr;
    }

    bool CharArray::isValidChar(char c) const {
        return (c == '0' || c == '1' || c == '2' || c == 'A' || c == 'B' || c == 'C' || c == 'D');
    }

    void CharArray::printCurrentInput() const {
        cout << "������� �������� �������: ";
        for (size_t i = 0; i < validCount; ++i) {
            cout << arr[i] << ' ';
        }
        cout << endl;
    }

    void CharArray::fillArray() {
        cout << "������� " << size << " �������� (0, 1, 2, A, B, C, D):\n";
        string invalidChars;

        // ���������� ������� �� ���������� ��������� �������
        while (validCount < size) {
            char inputChar;
            cin >> inputChar;

            if (isValidChar(inputChar)) {
                arr[validCount++] = inputChar; // ���������� ������ ���������� ��������
            }
            else {
                invalidChars += inputChar; // ���������� ������������� ������� � ������
            }

            // ����� ������������ ��������
            if (invalidChars.length() > 0) {
                cout << "������������ ������: " << invalidChars << ". ";
                printCurrentInput();
                cout << "����������, ������� ����������(-��) ������(-�).\n";
                invalidChars.clear();
            }
        }
    }

    void CharArray::findRareAndFrequentChars(vector<char>& rareChars, vector<char>& frequentChars) const {
        unordered_map<char, int> frequency;

        for (size_t i = 0; i < validCount; ++i) {
            frequency[arr[i]]++;
        }

        int minFrequency = numeric_limits<int>::max();
        int maxFrequency = numeric_limits<int>::min();

        // ����� ����������� � ������������ �������
        for (const auto& pair : frequency) {
            if (pair.second < minFrequency) {
                minFrequency = pair.second;
            }
            if (pair.second > maxFrequency) {
                maxFrequency = pair.second;
            }
        }

        // ���� ���� �������� � ����������� � ������������ ��������
        for (const auto& pair : frequency) {
            if (pair.second == minFrequency) {
                rareChars.push_back(pair.first);
            }
            if (pair.second == maxFrequency) {
                frequentChars.push_back(pair.first);
            }
        }
    }

    void CharArray::clearArray() {
        validCount = 0;
    }

}