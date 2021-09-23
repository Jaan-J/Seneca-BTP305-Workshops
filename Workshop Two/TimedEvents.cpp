/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iostream>
#include <iomanip>
#include "TimedEvents.h"

namespace sdds {
	TimedEvents::TimedEvents() :t_numRecords(0u), startTime{},endTime{} {};

	void TimedEvents::startClock() {
		startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock() {
		endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::addEvent(const char* ae) {
		if (ae != nullptr && ae[0] != '\0' && t_numRecords < maxRecords) {
			records[t_numRecords].s_eventName = ae;
			records[t_numRecords].s_units = "nanoseconds";
			records[t_numRecords].eventDuration = std::chrono::duration_cast <std::chrono::nanoseconds > (endTime - startTime);
			t_numRecords++;
		}
	}

	std::ostream& operator<<(std::ostream& os, TimedEvents& timedEvents) {
		os << "Execution Times:" << std::endl;
		os << "--------------------------" << std::endl;
		for (size_t i = 0; i < timedEvents.t_numRecords; ++i) {
			os << std::setw(20) << std::left << timedEvents.records[i].s_eventName <<
								   std::setw(12) << std::right << timedEvents.records[i].eventDuration.count() << " " <<
								   std::right << timedEvents.records[i].s_units << std::endl;
		}
		os << "--------------------------" << std::endl;
		return os;
	}
}
