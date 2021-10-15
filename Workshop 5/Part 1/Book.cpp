#include "Book.h"
namespace sdds{
  Book::Book():bookAuthor{""},bookTitle{""}, bookCountry{""},
  pubYear{0}, bookPrice{0},bookSummary{""}{}

  Book::Book(const std::string& strBook){
    std::string temp = strBook;
		std::string buffer;

		if (strBook != "")
		{
      buffer = temp.substr(0, temp.find(","));
			bookAuthor = temp.substr(temp.find_first_not_of(' '), temp.find(","));
			temp.erase(0, (bookAuthor.length() + 1));
      temp.erase(0,temp.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));


			bookTitle = temp.substr(0, temp.find_first_of(','));
      bookTitle = bookTitle.substr(0,bookTitle.find_last_of("abcdefghijklmnopqrstuvwxyz")+1);
			temp.erase(0, temp.find(',') + 1);
      temp.erase(0,temp.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));

			bookCountry = temp.substr(0,  temp.find(','));
			temp.erase(0, temp.find(","));
      temp.erase(0,temp.find_first_of("1234567890"));

			bookPrice = stod(temp.substr(0, temp.find(',')));
			temp.erase(0, temp.find(",") + 1);
      temp.erase(0, temp.find_first_of("1234567890"));

			pubYear = stod(temp.substr(0, temp.find(",")));
			temp.erase(0, temp.find(",") + 1);
      std::cout << temp << std::endl;

			bookSummary = temp.substr(temp.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), temp.find("."));
		}
  }

  const std::string& Book::title() const{
    return bookTitle;
  }

  const std::string& Book::country() const{
    return bookCountry;
  }

  const size_t& Book::year() const{
    return pubYear;
  }

  double& Book::price(){
    return bookPrice;
  }

  std::ostream& operator<<(std::ostream& os, const Book obj){
    os << std::setw(20) << obj.bookAuthor << " | ";
		os << std::setw(22) << obj.bookTitle << " | ";
		os << std::setw(5) << obj.bookCountry << " | ";
		os << std::setw(4) << obj.pubYear << " | ";
		os << std::setw(6) << std::fixed << std::setprecision(2) << obj.bookPrice << " | ";
		os << std::setw(6) << obj.bookSummary << std::endl;
		return os;
  }
}
