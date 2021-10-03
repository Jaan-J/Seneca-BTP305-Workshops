/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H
#include "Pair.h"
using std::size_t;

namespace sdds{
  template <class V, class K>
  class PairSummable: public Pair<V,K>{
    static V initial;
    static size_t minFieldWidth;
  public:
    PairSummable() = default;

    static const V& getInitialValue() {
        return initial;
    }

    PairSummable(const K& key, const V& value = initial):Pair<V,K>(key,value){
      if(minFieldWidth < key.size()){
        minFieldWidth = key.size();
      }
    }

    PairSummable& operator +=(const PairSummable& obj){
      if(this->key() == obj.key()){
        *this = PairSummable(obj.key(), (*this).value() + obj.value());
      }
      return *this;
    }

    bool isCompatibleWith(const PairSummable<V, K>& b) const{
      if (b.key() == this->key()){
        return true;
      }else{
        return false;
      }
    }

    void display(std::ostream& os) const{
      os.setf(std::ios::left);
			os.width(minFieldWidth);
      Pair<V, K>::display(os);
			os.unsetf(std::ios::left);
    }
  };

  template<>
  int PairSummable<int,std::string>::initial = 0;

  template<>
  std::string PairSummable<std::string,std::string>::initial = "";

  template <typename V, typename K>
  size_t PairSummable<V,K>::minFieldWidth = 0;

  template<>
  PairSummable<std::string,std::string>& PairSummable <std::string,std::string>
   ::operator+=(const PairSummable<std::string,std::string>& ps){
     if(this-> key() == ps.key()){
       if(this->value().empty()){
         *this = PairSummable(ps.key(),(*this).value() + ps.value());
       }
       else{
         *this = PairSummable(ps.key(),(*this).value() + ", " + ps.value());
       }
       return*this;
     }
     else{
       return*this;
     }
   }

}
#endif
