#include "lab7_2.h"

namespace lab07_2 {

    void Demo::inputValues() {
        cout << "������� �������� f1, c, i1, f2, i2 (����� ������): ";
        cin >> f1 >> c >> i1 >> f2 >> i2;
        cout << endl;
    }

    tuple<float, char, int, float, int> Demo::getFields() const {
        return make_tuple(f1, c, i1, f2, i2);
    }

    void Demo::outputValues(const string& filename) const {
        ofstream outFile(filename);

        if (!outFile) {
            cerr << "������ �������� ����� ��� ������." << endl;
            return;
        }

        cout << setfill('*') << setw(8) << fixed;
        outFile << setfill('*') << setw(8) << fixed;

        cout << "����� ���������� � ������� c, i2, f2, i1, f1: \n";

        // ����� �������
        cout << setw(8) << c << endl;
        outFile << setw(8) << c << endl;

        // ����� i2 � ������������ �������
        cout << setw(8) << oct << i2 << endl;
        outFile << setw(8) << oct << i2 << endl;

        // ����� f2 � ������ ���������
        cout << setprecision(2) << setw(8) << f2 << endl;
        cout << setprecision(1) << setw(8) << f2 << endl;
        cout << setprecision(1) << setw(8) << f2 << endl;
        outFile << setprecision(2) << setw(8) << f2 << endl;
        outFile << setprecision(1) << setw(8) << f2 << endl;
        outFile << setprecision(1) << setw(8) << f2 << endl;

        // ����� i1 � ������������ �������
        cout << setw(8) << oct << i1 << endl;
        outFile << setw(8) << oct << i1 << endl;

        // ����� f1 � ������ ���������
        cout << setprecision(2) << setw(8) << f1 << endl;
        cout << setprecision(1) << setw(8) << f1 << endl;
        cout << setprecision(1) << setw(8) << f1 << endl;
        outFile << setprecision(2) << setw(8) << f1 << endl;
        outFile << setprecision(1) << setw(8) << f1 << endl;
        outFile << setprecision(1) << setw(8) << f1 << endl;

        outFile.close();

        cout << "��������� ������� � ���� " << filename << endl;
    }

    ostream& operator<<(ostream& os, const Manip& manip) {

        os << setw(manip.width);

        switch (manip.base) {
        case 8:
            os << oct; // ������������ �������
            break;
        case 16:
            os << hex; // ����������������� �������
            break;
        default:
            os << dec; // ���������� �������
            break;
        }

        os << fixed << setprecision(manip.precision);

        os << setfill(manip.fillchar);

        return os;
    }
}