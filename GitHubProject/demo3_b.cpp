#include "lab3_b.h"
#include <vector>

using namespace std;

namespace lab03_b {
    void runDemo(){

        setlocale(LC_ALL, "RUS");

        size_t n;
        char choice;

        do {
            cout << "������� ������ �������: ";
            cin >> n;

            CharArray charArray(n);
            charArray.fillArray();

            vector<char> rareChars;
            vector<char> frequentChars;
            charArray.findRareAndFrequentChars(rareChars, frequentChars);

            cout << "�������� ����� ������������� �������: ";
            for (char c : rareChars) {
                cout << c << ' ';
            }
            cout << endl;

            cout << "�������� ����� ������������� �������: ";
            for (char c : frequentChars) {
                cout << c << ' ';
            }
            cout << endl << endl;

            charArray.clearArray();

            cout << "����� ������� ��� ���? (y/n): ";
            cin >> choice;
            cout << endl;

        } while (choice == 'y' || choice == 'Y');

    }
}