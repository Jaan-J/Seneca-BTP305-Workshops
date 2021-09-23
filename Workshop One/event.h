/*
Name: Jaan Javed
Student Number: 100131192
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_EVENT_H
#define SDDS_EVENT_H
#include <cstddef>
extern size_t g_sysClock;
namespace sdds {
	class Event {
		char* eventDescription;
		size_t sinceMidnight;

	public:
		Event();
		~Event();
		void display() const;
		void set(char* = nullptr);
		Event(const Event&);
		Event& operator=(const Event&);
	};
} // namespace sdds
#endif
