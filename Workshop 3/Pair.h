#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
namespace sdds{
  template <class V, class K>
  class Set{
    V valType;
    K keyType;
  public:
    Set(): valType{},keyType{},{
    }
    Pair(const K& key, const V& value){
      valType(value);
      keyType(key);
    }
    const V& value() const{return valType;}
    const K& key() const;{return keyType;}
    void display(std::ostream& os) const{
      os << keyType << ":" << valType << std::endl;
    }
  };
  template <class V, class K>
  std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair){
    pair.display(os);
    return os;
  }
}
#endif
