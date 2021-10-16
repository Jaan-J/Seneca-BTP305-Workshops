#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <iostream>

namespace sdds{
	class Movie{
		std::string movieTitle;
		size_t releaseYear;
		std::string movieDesc;
	public:
		Movie();
		const std::string& title() const;
		Movie(const std::string& strMovie);

		std::string& trim(std::string& o);

    friend std::ostream& operator<<(std::ostream&, const Movie&);

		template<typename T>
		void fixSpelling(T spellChecker){
			spellChecker(movieTitle);
			spellChecker(movieDesc);
		}

	};
}


#endif
