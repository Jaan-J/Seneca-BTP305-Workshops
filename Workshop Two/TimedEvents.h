#ifndef SDDS_TIMED_EVENTS_H
#define SDDS_TIMED_EVETS_H
#include<chrono>
#include <string>
namespace sdds {
	const int maxRecords = 10;
	class TimedEvents {
		size_t t_numRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endtime;
		struct{
			std::string s_eventName;
			std::string s_units = "nanoseconds";
			std::chrono::steady_clock::duration eventDuration;
		}records[maxRecords];
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void addEvent(const char*);
		friend std::ostream& operator<<(std::ostream&, TimedEvents&);
	};

}
#endif // !SDDS_TIME_EVENTS_H
