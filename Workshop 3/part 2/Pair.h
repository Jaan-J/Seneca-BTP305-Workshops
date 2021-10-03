/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include<ostream>
using std::ostream;

namespace sdds{
  template <class V, class K>
  class Pair{
    V valType;
    K keyType;
  public:
    Pair(): valType{0},keyType{0}{}

    Pair(const K& key, const V& value):valType (value), keyType(key){}

    const V& value() const{
      return valType;
    }

    const K& key() const{
      return keyType;
    }

    virtual void display(std::ostream& os) const{
      os << keyType << " : " << valType << std::endl;
    }

    friend ostream& operator<<(ostream& os, const Pair<V, K>& pair){
      pair.display(os);
      return os;
    }
  };
}
#endif
