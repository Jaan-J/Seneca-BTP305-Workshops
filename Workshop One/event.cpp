/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <iomanip>
#include "event.h"

using namespace std;

size_t g_sysClock = 0;
namespace sdds {

    Event::Event() {
        eventDescription = nullptr;
        sinceMidnight = 0;
    }

    Event::~Event() {
        if (eventDescription != nullptr) {
            delete[] eventDescription;
            eventDescription = nullptr;
        }
    }

    void Event::display() const {
        static int counter = 1;
        if (eventDescription != nullptr) {
            cout << setfill(' ') << setw(2) << counter << ". " << setfill('0') << setw(2) << sinceMidnight / 3600
                << ":" << setw(2) << (sinceMidnight % 3600) / 60 << ":" << setw(2)
                << (sinceMidnight % 60) << " => " << eventDescription << endl;
        }
        else {
            cout << setfill(' ') << setw(2) << counter << ". | No Event |" << endl;
        }
        counter += 1;
    }
    void Event::set(char* setEvent) {
        if (setEvent != nullptr && setEvent[0] != '\0') {
            delete[] eventDescription;
            size_t length = strlen(setEvent);
            sinceMidnight = g_sysClock;
            eventDescription = new char[length + 1];
            strcpy(eventDescription, setEvent);
            eventDescription[length] = '\0';
        }
        else {
            delete[] eventDescription;
            eventDescription = nullptr;
            sinceMidnight = 0;
        }

    }

    Event::Event(const Event& src) : eventDescription{ nullptr } {
        sinceMidnight = src.sinceMidnight;
        if (src.eventDescription != nullptr && src.eventDescription[0] != '\0') {
            size_t length = strlen(src.eventDescription);
            eventDescription = new char[length + 1];
            strcpy(eventDescription, src.eventDescription);
            eventDescription[length] = '\0';
        }
        else {
            delete[] eventDescription;
            eventDescription = nullptr;
        }
    }
    Event& Event::operator=(const Event& src) {
        if (this != &src) {
            sinceMidnight = src.sinceMidnight;
            delete[] eventDescription;
            if (src.eventDescription != nullptr) {
                size_t length = strlen(src.eventDescription);
                eventDescription = new char[length + 1];
                strcpy(eventDescription, src.eventDescription);
                eventDescription[length] = '\0';
            }
            else {
                delete[] eventDescription;
                eventDescription = nullptr;
            }
        }
        return *this;
    }
}