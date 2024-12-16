#include <tuple>
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

namespace lab07_2 {
    void runDemo();

    class Demo {
    private:
        float f1, f2;
        char c;
        int i1, i2;

    public:
        // Конструктор по умолчанию
        Demo() : f1(0), f2(0), c(' '), i1(0), i2(0) {}

        void inputValues();

        // Метод для получения всех полей в виде кортежа
        tuple<float, char, int, float, int> getFields() const;

        void outputValues(const string& filename) const;
    };

    class Manip {
    private:
        int width;
        int base;
        int precision;
        char fillchar;

    public:
        Manip(int p, int w, int b, char f) : precision(p), width(w), base(b), fillchar(f) {}

        friend ostream& operator<<(ostream& os, const Manip& manip);
    };
}