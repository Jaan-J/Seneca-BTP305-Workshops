/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "StringSet.h"
#include <fstream>
#include <string>
using std::ifstream;
using std::getline;
namespace sdds {
    StringSet::StringSet() : numStrings{ 0 } {
        stringArray = nullptr;
    }

    StringSet::StringSet(const char* filename) : numStrings{ 0 } {
        string buffer;
        ifstream file;
        file.open(filename);

        if (file.is_open()) {
            while (getline(file, buffer, ' ')) {
                ++numStrings;
            }
        }
        stringArray = new string[numStrings];
        for (size_t i = 0; i < numStrings; i++) {
            getline(file, stringArray[i], ' ');
        }
    }

    size_t StringSet::size() {
        return numStrings;
    }

    string StringSet::operator[](size_t index) {
        string temp;
        if (numStrings == 0) {
            return temp;
        }
        else {
            return stringArray[index];
        }
    }

    StringSet::StringSet(const StringSet& copyCon) {
        numStrings = copyCon.numStrings;
        stringArray = new string[copyCon.numStrings];
        for (int i = 0; i < copyCon.numStrings; i++) {
            stringArray[i] = copyCon.stringArray[i];
        }
    }

    StringSet& StringSet::operator=(const StringSet& src) {
        if (this != &src) {
            this->numStrings = src.numStrings;
            delete[] stringArray;
            stringArray = new string[numStrings];
            for (size_t i{ 0 }; i < numStrings; i++) {
                stringArray[i] = src.stringArray[i];
            }
        }
        else {
            delete[] stringArray;
            stringArray = nullptr;
        }
        return *this;
    }

    StringSet::~StringSet() {
        if (stringArray != nullptr) {
            delete[] stringArray;
            stringArray = nullptr;
        }
    }
}
