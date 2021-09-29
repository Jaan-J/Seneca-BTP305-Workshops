#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H
#include "Set.h"
namespace sdds{
  template <size_T N, typename T>
  class SetSummable : public Set<N,T>{
  public:
    T accumulate(const std::string& filter) const{
      T locObj(filter);
      for(size_t i = 0; i < *this.size(); i++){
        if (localObj.isCompatibleWith((*this).get(i))){
          locObj += *this.get(i);
        }
      }
      return locObj;
    }
  };
}
#endif
