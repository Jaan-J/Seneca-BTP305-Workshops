/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_STRING_SET_H
#define SDDS_STRING_SET_H
#include <iostream>
using std::string;
namespace sdds {
  class StringSet{
    string* stringArray;
    static size_t numStrings;
  public:
    StringSet();
    ~StringSet();
    StringSet(const char*);
    size_t size();
    std::string operator[](size_t);
    StringSet(const StringSet&);
    StringSet& operator=(const StringSet &);
  };

}
#endif // !SDDS_STRING_SET_H
