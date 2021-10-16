#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"

namespace sdds{
 Movie::Movie():movieTitle{""},releaseYear{0},movieDesc{""}{};

 std::string& Movie::trim(std::string& o){
   o = o.substr(o.find_first_not_of(' '), o.find_last_not_of(' ') - o.find_first_not_of(' ') + 1);
   return o;
 }

 const std::string& Movie::title() const{
   return movieTitle;
 }

 Movie::Movie(const std::string& strMovie){
   std::string temp = strMovie;
   std::string search;

   for (auto i = 0u; i <= 2; i++){
     switch (i){
       case 0:
       search = temp.substr(0, temp.find(','));
       movieTitle = trim(search);
       break;
       case 1:
       search = temp.substr(0, temp.find(','));
       releaseYear = stoi(trim(search));
       break;
       case 2:
       search = temp.substr(0, temp.find('.') + 1);
       movieDesc = trim(search);
       break;
     }
     if (i < 2){
       temp.erase(0, temp.find(',') + 1);
     }
   }
 }

 std::ostream& operator<<(std::ostream& os, const Movie& o){
   os << std::setw(40) << o.movieTitle << " | ";
   os << std::setw(4) << o.releaseYear << " | ";
   os << o.movieDesc << std::endl;
   return os;
 }
}
