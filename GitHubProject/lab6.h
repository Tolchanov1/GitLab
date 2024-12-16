#pragma once

#include <map>

using namespace std;

namespace lab06 {
    void runDemo();

    template <typename T>
    class FrequencyCounter {
    public:
        FrequencyCounter();
        void addData(const T& element);
        void findLeastFrequent(T* result, int& count);
        template <typename... Args>
        void print(Args... args);

    private:
        map<T, int> frequencyMap;
    };
}




// 1. Не используется вектор.
// 2. Мапа выводит все элементы.
// 3. Программа ищет все наиболее редко встречающиеся числа и символы.
// 4. Реализована функция print с многоточием.