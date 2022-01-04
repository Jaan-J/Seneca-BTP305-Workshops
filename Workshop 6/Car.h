/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CAR_H
#define SDDS_CAR_H

#include <string>
#include "Vehicle.h"

using namespace std;
namespace sdds {
	class Car : public Vehicle {
		string make{};
		char carCond{};
		double carSpeed{};

	public:
		Car(std::istream& in); 
		string condition() const;
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
} 
#endif