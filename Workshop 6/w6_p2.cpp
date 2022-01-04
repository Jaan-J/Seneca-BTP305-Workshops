#include <iostream>
#include <iomanip>
#include <fstream>
#include "Autoshop.h"
#include "Autoshop.h"
#include "Utilities.h"
#include "Utilities.h"
using namespace std;
void loadData(const char* filename, sdds::Autoshop& as)
{
	ifstream file(filename);
	if (!file)
	{
		cerr << "ERROR: Cannot open file [" << filename << "].\n";
		return;
	}
	while (file)
	{
		// TODO: This code can throw errors to signal that something went wrong while
		//         extracting data. Write code to catch and handle the following errors:
		//       - the type of vehicle is not recognized: the first non-empty character
		//           on the line is not 'c', 'C', 'r', or 'R'. In this case print
		//           "Unrecognized record type: [TAG]<endl>"
		//       - one of the fields in the record contains invalid data. In this case print
		//           "Invalid record!<endl>"

		try {
			sdds::Vehicle* aVehicle = sdds::createInstance(file);
			if (aVehicle)
				as += aVehicle;
		}
		catch (string err) {
			cout << err << endl;
		}
	}
}

// ws dataClean.txt dataMessy.txt
int main(int argc, char** argv)
{
	cout << "Command Line:\n";
	cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		cout << setw(3) << i + 1 << ": " << argv[i] << '\n';
	cout << "--------------------------\n\n";

	sdds::Autoshop as;
	loadData(argv[1], as);
	as.display(cout);
	cout << "\n";
	loadData(argv[2], as);
	as.display(cout);

	cout << endl;
	list<const sdds::Vehicle*> vehicles;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle has a top speed >300km/h

		auto fastVehicles = [&](const sdds::Vehicle* fast) {
			return fast->topSpeed() > 300;
		};

		as.select(fastVehicles, vehicles);
		cout << "--------------------------------\n";
		cout << "|       Fast Vehicles          |\n";
		cout << "--------------------------------\n";
		for (auto it = vehicles.begin(); it != vehicles.end(); ++it)
		{
			(*it)->display(cout);
			cout << endl;
		}
		cout << "--------------------------------\n";
	}

	vehicles.clear();
	cout << endl;
	{
		// TODO: Create a lambda expression that receives as parameter `const sdds::Vehicle*`
		//         and returns true if the vehicle is broken and needs repairs.

		auto brokenVehicles = [&](const sdds::Vehicle* broken) {
			return broken->condition()[0] == 'b';
		};

		as.select(brokenVehicles, vehicles);
		cout << "--------------------------------\n";
		cout << "| Vehicles in need of repair   |\n";
		cout << "--------------------------------\n";
		for (const auto vehicle : vehicles)
		{
			vehicle->display(cout);
			cout << endl;
		}
		cout << "--------------------------------\n";
	}

	return 0;
}