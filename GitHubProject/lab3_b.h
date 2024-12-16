#pragma once

#include <iostream>
#include <unordered_map>

namespace lab03_b {
    void runDemo();

    class CharArray {
    private:
        char* arr;
        size_t size;
        size_t validCount;

    public:
        CharArray(size_t n);
        ~CharArray();
        void fillArray();
        void findRareAndFrequentChars(std::vector<char>& rareChars, std::vector<char>& frequentChars) const;
        bool isValidChar(char c) const;
        void printCurrentInput() const;
        void clearArray();
    };
}