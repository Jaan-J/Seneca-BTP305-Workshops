/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H

#include "Vehicle.h"
#include "Car.h"
#include "Racecar.h"

using namespace std;
namespace sdds {
	Vehicle* createInstance(std::istream& in);
} 
#endif