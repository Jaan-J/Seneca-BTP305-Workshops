/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "SongCollection.h"
#include <list>
#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#include <algorithm>
#include <vector>
#include <fstream>


namespace sdds{
	SongCollection::SongCollection(const char* file){
		std::fstream f(file);
		std::string buffer;

		if (std::string(file) == std::string("songs.txt")){
			if (f.good()){
				while (std::getline(f, buffer))

				if (!buffer.empty()){
					Song temp(buffer);
					songVec.push_back(temp);
					songVecSize += songVec.back().songLength;
				}
			}
		}
		else{
			throw "ERROR: Invalid File";
		}
		f.close();
	}

	SongCollection::SongCollection(){
		songVecSize = 0;
	}



	void SongCollection::sort(const std::string& sc){
		auto Compare = [sc](Song song1, Song song2){
			std::string sorted(sc);

			if (sc == std::string("title"))
				return song1.songTitle < song2.songTitle;
			else if (sorted == std::string("album"))
				return song1.songAlb < song2.songAlb;
			else 
				return song1.songLength < song2.songLength;
		};

		std::sort(songVec.begin(), songVec.end(), Compare);
	}


	void SongCollection::cleanAlbum(){
		auto cA = [](Song& song){
			if (song.songAlb == std::string("[None]"))
				song.songAlb.clear();
		};

		std::for_each(songVec.begin(), songVec.end(), cA);
	}


	bool SongCollection::inCollection(const std::string& sc) const{
		return std::any_of(songVec.begin(), songVec.end(), [sc](const Song& song) {return song.songArtist == std::string(sc); });
	}


	std::list<Song> SongCollection::getSongsForArtist(const std::string& sc) const{
		std::list<Song> availList(songVec.size());
		auto it = std::copy_if(songVec.begin(), songVec.end(), availList.begin(), [sc](const Song& song) {return song.songArtist == std::string(sc); });
		availList.resize(std::distance(availList.begin(), it));
		return availList;
	}


	std::ostream& operator<<(std::ostream& os, const Song& obj){

		auto songDur = [](int d){
			std::string duration;
			int mins;
			mins = d / 60;
			duration = std::to_string(int(mins % 60));
			duration += ":";
			duration += int(d % 60) < 10 ? "0" + std::to_string(int(d % 60)) : std::to_string(int(d % 60));

			return duration;
		};

		os << "| " << std::left << std::setw(20) << obj.songTitle << " | ";
		os << std::left << std::setw(15) << obj.songArtist << " | ";
		os << std::left << std::setw(20) << obj.songAlb << " | ";
		if (obj.songYear != 0)
			os << std::right << std::setw(6) << obj.songYear;
		else
			os << std::right << std::setw(6) << "";
		os << " | ";
		os << songDur(obj.songLength) << " | ";
		os << std::setprecision(2) << std::fixed << obj.m_price << " |";
		return os;
	}


	void SongCollection::display(std::ostream& os) const{
		auto fixFormat = [](int d) {
			std::string duration;
			int hours = 0;
			int mins = 0;
			mins = d / 60;
			hours = mins / 60;
			duration = std::to_string(hours);
			duration += ":";
			duration += int(mins % 60) < 10 ? std::string("0") + std::to_string(int(mins % 60)) : std::to_string(int(mins % 60));
			duration += ":";
			duration += int(d % 60) < 10 ? std::string("0") + std::to_string(int(d % 60)) : std::to_string(int(d % 60));
			return duration;
		};
		
		std::for_each(songVec.begin(), songVec.end(), [&](const Song song) { os << song << std::endl; });
		
		os << "----------------------------------------------------------------------------------------" << std::endl;
		os << "|";
		os << "                                                        Total Listening Time: ";
		os << fixFormat(std::accumulate(songVec.begin(), songVec.end(), 0, [](int sum, const Song song) { return song.songLength + sum; }));
		os << " |" << std::endl;

	}


	Song::Song(const std::string& str)
	{
		clearSong();
		std::string temp = str;
		std::string buffer;

		for (auto i = 0u; i <= 5; i++){

			switch (i){
			case 0:
				buffer = temp.substr(0, 25);
				songTitle = buffer.substr(buffer.find_first_not_of(' '), buffer.find_last_not_of(' ') - buffer.find_first_not_of(' ') + 1); 
				break;
			case 1:
				buffer = temp.substr(0, 25);
				songArtist = buffer.substr(buffer.find_first_not_of(' '), buffer.find_last_not_of(' ') - buffer.find_first_not_of(' ') + 1);
				break;
			case 2:
				buffer = temp.substr(0, 25);
				songAlb = buffer.substr(buffer.find_first_not_of(' '), buffer.find_last_not_of(' ') - buffer.find_first_not_of(' ') + 1);
				break;
			case 3:
				buffer = temp.substr(0, 5);
				if(!buffer.find_first_not_of(' '))
				songYear = stoi(buffer.substr(buffer.find_first_not_of(' '), buffer.find_last_not_of(' ') - buffer.find_first_not_of(' ') + 1));
				break;
			case 4:
				buffer = temp.substr(0, 5);
				songLength = stoi(buffer.substr(buffer.find_first_not_of(' '), buffer.find_last_not_of(' ') - buffer.find_first_not_of(' ') + 1));
				break;
			case 5:
				buffer = temp.substr(temp.find_first_not_of(' '), 5);
				m_price = stod(buffer.substr(buffer.find_first_not_of(' '), buffer.find_last_not_of(' ') - buffer.find_first_not_of(' ') + 1));
				break;
			}
			if (i < 5){
				temp.erase(0, buffer.find_last_of(' ') + 1);
			}
		}
	}


	void Song::clearSong(){
		songLength = 0;
		m_price = 0;
		songArtist = "";
		songAlb = "";
		songTitle = "";
		songYear = 0;
	}


	Song::Song(){
		clearSong();
	}



}