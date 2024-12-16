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




// 1. �� ������������ ������.
// 2. ���� ������� ��� ��������.
// 3. ��������� ���� ��� �������� ����� ������������� ����� � �������.
// 4. ����������� ������� print � �����������.