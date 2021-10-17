/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

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
   std::string buffer = strMovie;
   std::string search;

   for (size_t i = 0; i <= 2; i++){
     switch (i){
       case 0:
       search = buffer.substr(0, buffer.find(','));
       movieTitle = trim(search);
       break;
       case 1:
       search = buffer.substr(0, buffer.find(','));
       releaseYear = stoi(trim(search));
       break;
       case 2:
       search = buffer.substr(0, buffer.find('.') + 1);
       movieDesc = trim(search);
       break;
     }
     if (i < 2){
       buffer.erase(0, buffer.find(',') + 1);
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
