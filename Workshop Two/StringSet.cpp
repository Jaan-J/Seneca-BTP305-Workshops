#include "StringSet.h"
#include <fstream>
using std::ifstream;
using std::getline;
namespace sdds{
  size_t StringSet::numStrings = 0;
  StringSet::StringSet():stringArray(nullptr){}

  StringSet::~StringSet(){
    if(stringArray != nullptr){
      delete[] stringArray;
      stringArray = nullptr;
    }
  }

  StringSet::StringSet(const char* filename){
    string buffer = {};
    ifstream file;
    file.open(filename);

    if(file.is_open()){
      while(getline(file,buffer,' ')){
        ++numStrings;
      }
    }

    stringArray = new string[numStrings];
    int d = 0;
    string copy = {};
    while(getline(file,copy,' ')){
      stringArray[d] = copy;
    }
  }

  size_t StringSet::size(){
    return numStrings;
  }


  string StringSet::operator[](size_t index){
    string temp="";
    if(stringArray[index].empty()){
      return temp;
    }
    else{
      return stringArray[index];
    }
  }

  StringSet::StringSet(const StringSet& copyCon){
    *this = copyCon;
  }
  StringSet& StringSet::operator=(const StringSet& src){
    if(this != &src){
      this->numStrings = src.numStrings;
      delete[] stringArray;
      stringArray = new string[numStrings];
      for(size_t i{0}; i < numStrings; i++){
        stringArray[i] = src.stringArray[i];
      }
    }
    return *this;
  }

}
