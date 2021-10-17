/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>

namespace sdds{
	class Movie{
		std::string movieTitle;
		size_t releaseYear;
		std::string movieDesc;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);
    friend std::ostream& operator<<(std::ostream&, const Movie&);
		std::string& trim(std::string& o);

		template<typename T>
		void fixSpelling(T spellChecker){
			spellChecker(movieTitle);
			spellChecker(movieDesc);
		}

	};
}
#endif
