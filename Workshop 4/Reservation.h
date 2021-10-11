#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <iomanip>
#include <string>
#include <iostream>

using namespace std;

namespace sdds {
    class Reservation {
        string resID, resName,resEmail;
        int resNumPpl, resDay, resHour;
    public:
        Reservation() = default;
        void update(int, int);
        Reservation(const string&);
        friend ostream& operator<<(ostream&, const Reservation&);
    };
}

#endif
