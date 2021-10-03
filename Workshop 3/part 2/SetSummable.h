/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"

namespace sdds{
  template <unsigned int N, class T>
  class SetSummable : public Set<N,T>{
  public:
    T accumulate(const std::string& filter) const{
      T locObj(filter);
      for(size_t i = 0; i < this->size(); i++){
        if (locObj.isCompatibleWith(this->get(i))){
          locObj += this->get(i);
        }
      }
      return locObj;
    }
  };
}
#endif
