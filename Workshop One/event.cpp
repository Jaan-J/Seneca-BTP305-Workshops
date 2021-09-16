#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "event.h"

using namespace std;

size_t g_sysClock = 0;
namespace sdds {

    void Event::display(){
        static int counter = 1;
        if (eventDescription[0] != '\0') {
            cout << counter << ". " << setfill('0') << setw(2) << sinceMidnight / 3600
                << ":" << setw(2) << (sinceMidnight % 3600) / 60 << ":" << setw(2)
                << (sinceMidnight % 60) << " -> " << eventDescription << endl;
        }
        else {
            cout << counter << ". [ No Event ] " << endl;
        }
        counter += 1;
    }
    void Event::set(char* setEvent) {
        if (setEvent != nullptr) {
            strcpy(eventDescription, setEvent);
            sinceMidnight = g_sysClock;
        }
        else {
            eventDescription[0] = '\0';
            sinceMidnight = 0;
        }
    }

    Event::Event() {
        eventDescription[0] = '\0';
        sinceMidnight = 0;
    }
} // namespace sdds