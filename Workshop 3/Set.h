#ifndef SDDS_SET_H
#define SDDS_SET_H
#include <iostream>
using std::size_t;
namespace sdds{
  template <class T, int N>
  class Set{
    size_t numElements = 0;
    T m_set[N];
  public:
    size_t size() const{
      return numElements;
    }

    const T& get(size_t idx) const{
      return m_set[idx];
    }

    void operator +=(const T& item){
      if(numElements < N){
        m_set[numElements] = item;
        numElements++;
      }
    }

  };
}
#endif
