/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Autoshop.h"
#include "Car.h"

namespace sdds {

	Autoshop& Autoshop::operator+=(Vehicle* theVehicle) {
		m_vehicles.push_back(theVehicle);	
		return *this;
	}

	void Autoshop::display(ostream& out){
		out << "--------------------------------\n";
		out << "| Cars in the autoshop!        |\n";
		out << "--------------------------------\n";

		vector<Vehicle*>::iterator i;
		for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			(*i)->display(out);
			out << endl;
		}

		out << "--------------------------------\n";
	}

	Autoshop::~Autoshop() {
		std::vector<Vehicle*>::iterator i;
		for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
			delete* i;
		}
	}
} // sdds