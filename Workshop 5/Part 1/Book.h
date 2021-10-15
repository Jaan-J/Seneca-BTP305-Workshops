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

  };
}
#endif
