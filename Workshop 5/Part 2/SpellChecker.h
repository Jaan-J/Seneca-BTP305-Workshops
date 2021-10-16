#ifndef SDDS_SPELLCHECKER_H
#define SDDS_SPELLCHECKER_H
#include <iostream>

namespace sdds{
	class SpellChecker{
    std::string m_badWords[6];
		std::string m_goodWords[6];
  public:
		SpellChecker(const char* filename);
		void operator()(std::string& text) const;
	};
}

#endif
