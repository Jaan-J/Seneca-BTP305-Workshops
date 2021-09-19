#ifndef SDDS_TIME_EVENTS_H
#define SDDS_TIME_EVETS_H
#include<chrono>
#include <string>
namespace sdds {
	const int maxRecords = 7;
	class TimedEvents {
		int t_numRecords;
		std::chrono::steady_clock::time_point startTime;
		std::chrono::steady_clock::time_point endtime;
		struct eventDetails {
			std::string s_eventName;
			std::string s_units = "seconds";
			std::chrono::steady_clock::duration eventDuration;
		};
	public:
		TimedEvents();
		void startClock();
		void stopClock();
		friend std::ostream& operator<<(std::ostream&, TimedEvents);
	};

}
#endif // !SDDS_TIME_EVENTS_H
