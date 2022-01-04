/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H
#include <iostream>
#include <list>
#include <vector>

namespace sdds{
	struct Song{
		std::string songArtist;
		std::string songTitle;
		std::string songAlb;
		double m_price;
		int songYear;
		unsigned int songLength;
		Song(const std::string&);
		Song();
		void clearSong();
	};

	class SongCollection{
		unsigned int songVecSize;
		std::vector<Song> songVec;
	public:
		SongCollection();
		SongCollection(const char*);
		void display(std::ostream& out) const;
		void sort(const std::string&);
		void cleanAlbum();
		bool inCollection(const std::string&) const;
		std::list<Song> getSongsForArtist(const std::string&) const;
	};

	std::ostream& operator<<(std::ostream&, const Song&);
}
#endif 

