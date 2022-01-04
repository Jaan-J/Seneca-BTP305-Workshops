/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H

#include <list>
#include <vector>
#include "Vehicle.h"

using namespace std;
namespace sdds {
	class Autoshop {
		std::vector<Vehicle*> m_vehicles; 

	public:
		Autoshop& operator+=(Vehicle* theVehicle);
		void display(std::ostream& out);
		~Autoshop();


		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles) {
			std::vector<Vehicle*>::iterator i;
			for (i = m_vehicles.begin(); i != m_vehicles.end(); i++) {
				if (test(*i)) {
					vehicles.push_back(*i);
				}
			}
		}
	};
}
#endif