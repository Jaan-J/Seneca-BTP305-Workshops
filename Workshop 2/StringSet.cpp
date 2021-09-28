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
        file.close();
        stringArray = new string[numStrings];
        file.open(filename);
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

    StringSet::StringSet(const StringSet& copyCon){
      stringArray = nullptr;
      numStrings = 0;
      *this = copyCon;
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
        return *this;
    }

    StringSet::~StringSet() {
        if (stringArray != nullptr) {
            delete[] stringArray;
            stringArray = nullptr;
        }
    }

    StringSet& StringSet::operator = (StringSet&& src){
      if(this != &src){
        delete[] stringArray;
        stringArray = src.stringArray;
        numStrings = src.numStrings;
        src.stringArray = nullptr;
        src.numStrings = 0;
      }
      return *this;
    }

    StringSet::StringSet(StringSet&& src):stringArray(nullptr),numStrings(0){
      numStrings = src.numStrings;
  		stringArray = src.stringArray;
      src.numStrings = 0;
      src.stringArray = nullptr;
    }
}
