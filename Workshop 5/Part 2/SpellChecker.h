/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

namespace sdds{
	class SpellChecker{
    std::string m_badWords[6];
		std::string m_goodWords[6];
		static int m_modifiedCount[6];
  public:
		SpellChecker(const char* filename);
		void operator()(std::string& text);
		void showStatistics(std::ostream& out) const;
	};
}
#endif
