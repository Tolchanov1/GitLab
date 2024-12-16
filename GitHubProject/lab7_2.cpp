#include "lab7_2.h"

namespace lab07_2 {

    void Demo::inputValues() {
        cout << "Введите значения f1, c, i1, f2, i2 (через пробел): ";
        cin >> f1 >> c >> i1 >> f2 >> i2;
        cout << endl;
    }

    tuple<float, char, int, float, int> Demo::getFields() const {
        return make_tuple(f1, c, i1, f2, i2);
    }

    void Demo::outputValues(const string& filename) const {
        ofstream outFile(filename);

        if (!outFile) {
            cerr << "Ошибка открытия файла для записи." << endl;
            return;
        }

        cout << setfill('*') << setw(8) << fixed;
        outFile << setfill('*') << setw(8) << fixed;

        cout << "Вывод переменных в порядке c, i2, f2, i1, f1: \n";

        // Вывод символа
        cout << setw(8) << c << endl;
        outFile << setw(8) << c << endl;

        // Вывод i2 в восьмеричной системе
        cout << setw(8) << oct << i2 << endl;
        outFile << setw(8) << oct << i2 << endl;

        // Вывод f2 с разной точностью
        cout << setprecision(2) << setw(8) << f2 << endl;
        cout << setprecision(1) << setw(8) << f2 << endl;
        cout << setprecision(1) << setw(8) << f2 << endl;
        outFile << setprecision(2) << setw(8) << f2 << endl;
        outFile << setprecision(1) << setw(8) << f2 << endl;
        outFile << setprecision(1) << setw(8) << f2 << endl;

        // Вывод i1 в восьмеричной системе
        cout << setw(8) << oct << i1 << endl;
        outFile << setw(8) << oct << i1 << endl;

        // Вывод f1 с разной точностью
        cout << setprecision(2) << setw(8) << f1 << endl;
        cout << setprecision(1) << setw(8) << f1 << endl;
        cout << setprecision(1) << setw(8) << f1 << endl;
        outFile << setprecision(2) << setw(8) << f1 << endl;
        outFile << setprecision(1) << setw(8) << f1 << endl;
        outFile << setprecision(1) << setw(8) << f1 << endl;

        outFile.close();

        cout << "Результат записан в файл " << filename << endl;
    }

    ostream& operator<<(ostream& os, const Manip& manip) {

        os << setw(manip.width);

        switch (manip.base) {
        case 8:
            os << oct; // Восьмеричная система
            break;
        case 16:
            os << hex; // Шестнадцатеричная система
            break;
        default:
            os << dec; // Десятичная система
            break;
        }

        os << fixed << setprecision(manip.precision);

        os << setfill(manip.fillchar);

        return os;
    }
}