/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Utilities.h"
#include <sstream>

namespace sdds {
	Vehicle* createInstance(istream& in) {
		string buffer;	
		getline(in, buffer);

		buffer.erase(0, buffer.find_first_not_of(' '));
		stringstream line(buffer);


		Vehicle* vehicle = nullptr;
		if (!buffer.empty()) {

			if (toupper(buffer[0]) == 'R') {
				vehicle = new Racecar(line);
			}

			else if (toupper(buffer[0]) == 'C') {
				vehicle = new Car(line);
			}
	
			else {
				string error{};
				getline(line, error, ',');
				throw "Unrecognized record type: [" + error + "]";
			}
		}

		else {
			vehicle = nullptr;

		}
		return vehicle;
	}
} // sdds