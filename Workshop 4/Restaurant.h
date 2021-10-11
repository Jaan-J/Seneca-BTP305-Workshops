#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include <iostream>
#include "Reservation.h"

namespace sdds {
    class Restaurant {
        Reservation* resDetails = nullptr;
        size_t resNum;
    public:
        Restaurant(const Reservation* reservations[], size_t cnt);
        size_t size() const;

        Restaurant(const Restaurant&);
        Restaurant& operator=(const Restaurant&);

        Restaurant(Restaurant&&);
        Restaurant& operator=(Restaurant&&);
        ~Restaurant();

        friend ostream& operator<<(ostream& ostr, Restaurant& other);
    };
}

#endif
