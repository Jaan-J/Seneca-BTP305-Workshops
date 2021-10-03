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
