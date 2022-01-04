/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <cctype>
#include <iostream>
#include <iomanip>

#include "Car.h"

namespace sdds {
	Car::Car(istream& in) {

		bool flag = true;

		string tag;
		getline(in, tag, ',');
		getline(in, make, ',');

		string condition;
		getline(in, condition, ',');

		string speed;
		getline(in, speed, ',');

		make.erase(0, make.find_first_not_of(' '));
		make.erase(make.find_last_not_of(' ') + 1);

	
		condition.erase(0, condition.find_first_not_of(' '));
		condition.erase(condition.find_last_not_of(' ') + 1);

	
		speed.erase(0, speed.find_first_not_of(' '));
		speed.erase(speed.find_last_not_of(' ') + 1);

	
		if (condition.empty() || condition[0] == ' ') {
			carCond = 'n';
		}
		else if (condition[0] == 'b' || condition[0] == 'n' || condition[0] ==
			'u') {
			carCond = condition[0];
		}
		
		else {
			string err = "Invalid record!";
			throw err;
		}

		for (int tmp : speed) {
			if (tmp < 48 || tmp > 57) {
				flag = false;
				break;
			}
		}

		if (flag) {
			carSpeed = stod(speed);
		}

		else {

			string err = "Invalid record!";
			throw err;
		}
	}

	string Car::condition() const {
		string condition;
		switch (carCond) {
		case 'b':
			condition.assign("broken");
			break;
		case 'u':
			condition.assign("used");
			break;
		case 'n':
			condition.assign("new");
			break;
		}
		return condition; 
	}

	double Car::topSpeed() const {
		return carSpeed;	
	}

	void Car::display(ostream& out) const {
		out << "| " << right << setw(10) << make;
		out << " | " << left << setw(6) << condition();
		out << " | " << setw(6) << fixed << setprecision(2) << topSpeed();
		out << " |";
	}
} 