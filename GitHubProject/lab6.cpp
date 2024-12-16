#include "lab6.h"
#include <iostream>

using namespace std;

namespace lab06 {

    template <typename T> FrequencyCounter<T>::FrequencyCounter() {}

    template <typename T> void FrequencyCounter<T>::addData(const T& element) {
        frequencyMap[element]++;
    }

    template <typename T> void FrequencyCounter<T>::findLeastFrequent(T* result, int& count) {
        for (const auto& pair : frequencyMap) {
            cout << "�������: " << pair.first << ", �������: " << pair.second << endl;
        }

        int minFrequency = numeric_limits<int>::max();
        for (const auto& pair : frequencyMap) {
            if (pair.second < minFrequency) {
                minFrequency = pair.second;
            }
        }

        count = 0;
        for (const auto& pair : frequencyMap) {
            if (pair.second == minFrequency) {
                result[count++] = pair.first; // ���������� �������� � ������
            }
        }
    }

    template <typename T>
    template <typename... Args>
    void FrequencyCounter<T>::print(Args... args) {
        (cout << ... << args) << endl;
    }

    // ����� ������������� ������� ������
    template class FrequencyCounter<int>;
    template class FrequencyCounter<char>;

    // ����� ������������� ���������� �������
    template void FrequencyCounter<int>::print(const char*);
    template void FrequencyCounter<char>::print(const char*);

}