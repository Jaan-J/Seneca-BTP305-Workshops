/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
#include <iomanip>

namespace sdds{
  class Book{
    std::string bookAuthor;
    std::string bookTitle;
    std::string bookCountry;
    size_t pubYear;
    double bookPrice;
    std::string bookSummary;
  public:
    Book();
    Book(const std::string&);
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();

    friend std::ostream& operator<<(std::ostream&, const Book);

    template <typename T>
    void fixSpelling(T& spellChecker){
      spellChecker(bookSummary);
    }

  };
}
#endif
