#include <iostream>
#include <fstream>
#include <string>
#include "SpellChecker.h"

namespace sdds{
	SpellChecker::SpellChecker(const char* filename){
    std::ifstream fileA(filename);
    if (filename == nullptr || !fileA){
      throw "Bad file name!";
    }

			std::string misspelledLine;
			std::string misspelledWord;
			for (size_t i = 0; i < 6 && fileA; ++i){
        std::getline(fileA, misspelledLine);
				misspelledWord = misspelledLine.substr(0, misspelledLine.find_first_of(' '));
				m_badWords[i] = misspelledWord;

				misspelledLine.erase(0, misspelledLine.find_first_of(' '));
				misspelledWord = misspelledLine.substr(misspelledLine.find_first_not_of(' '), misspelledLine.find_last_not_of(' '));
				m_goodWords[i] = misspelledWord;
      }
    }

	void SpellChecker::operator()(std::string& text) const{
    for (auto i = 0u; i < 6; i++){
      size_t index = text.find(m_badWords[i], 0);
      while (index != std::string::npos){
        text.replace(index, m_badWords[i].length(), m_goodWords[i]);
        index = text.find(m_badWords[i], index + 1);
      }
		}
	}

};
