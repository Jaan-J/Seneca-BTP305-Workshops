#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include "Pair.h"
using std::size_t;
namespace sdds{
  template <class V, class K>
  class PairSummable: public Pair<V,K>{
    static V initial;
    static  size_t minFieldWidth;
  public:
    PairSummable(){};

    PairSummable(const K& key, const V& value = initial):Pair<V,K>(value,key){
      if(minFieldWidth < key.size()){
        minFieldWidth = key.size();
      }
    }

    bool isCompatibleWith(const PairSummable<V, K>& b) const{
      if (b == this->keyType)
        return true;
       else
        return false;
    }

    PairSummable& operator +=(PairSummable& obj){
      *this = PairSummable(obj.key(), (*this).value() + obj.value());
      return *this;
    }

    void display(std::ostream& os) const{
      os.setf(std::ios::left);
			os.width(minFieldWidth);
      Pair<V, K>::display(os);
			os.unsetf(std::ios::left);
    }
  };

}
#endif
