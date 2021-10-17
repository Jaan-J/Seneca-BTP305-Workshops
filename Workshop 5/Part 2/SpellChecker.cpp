/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "SpellChecker.h"

namespace sdds{
int SpellChecker:: m_modifiedCount[6] = {0};

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

	void SpellChecker::operator()(std::string& text){
    for (int i = 0; i < 6; ++i){
      while (text.find(m_badWords[i]) != std::string::npos){
        text.replace(text.find(m_badWords[i]), m_badWords[i].size(), m_goodWords[i]);
				m_modifiedCount[i]++;
      }
		}

	}

	void SpellChecker::showStatistics(std::ostream& out) const{
		std::cout << "Spellchecker Statistics" << std::endl;
		for(int i = 0; i < 6; i++){
			std::cout << std::setw(15) << std::right << m_badWords[i] << ": " << m_modifiedCount[i] << " replacements" << std::endl;
		}
	}
};
