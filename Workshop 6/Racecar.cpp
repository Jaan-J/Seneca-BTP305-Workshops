/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Racecar.h"

namespace sdds {
	Racecar::Racecar(istream& in) : Car(in) {
		string buffer;
		getline(in, buffer, '\n');
		m_booster = stod(buffer);
	}

	void Racecar::display(ostream& out) const {
		Car::display(out);
		out << "*";
	}

	double Racecar::topSpeed() const {
		return Car::topSpeed() * (1 + m_booster);  
	}
} // sdds