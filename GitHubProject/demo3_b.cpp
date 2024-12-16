#include "lab3_b.h"
#include <vector>

using namespace std;

namespace lab03_b {
    void runDemo(){

        setlocale(LC_ALL, "RUS");

        size_t n;
        char choice;

        do {
            cout << "Введите размер массива: ";
            cin >> n;

            CharArray charArray(n);
            charArray.fillArray();

            vector<char> rareChars;
            vector<char> frequentChars;
            charArray.findRareAndFrequentChars(rareChars, frequentChars);

            cout << "Наименее часто встречающиеся символы: ";
            for (char c : rareChars) {
                cout << c << ' ';
            }
            cout << endl;

            cout << "Наиболее часто встречающиеся символы: ";
            for (char c : frequentChars) {
                cout << c << ' ';
            }
            cout << endl << endl;

            charArray.clearArray();

            cout << "Найти символы ещё раз? (y/n): ";
            cin >> choice;
            cout << endl;

        } while (choice == 'y' || choice == 'Y');

    }
}