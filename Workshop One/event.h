#ifndef EVENT_H
#define EVENT_H
extern size_t g_sysClock;
namespace sdds {
	class Event {
		char eventDescription[128];
		unsigned int sinceMidnight;

	public:
		Event();
		void display();
		void set(char* desc = nullptr);
	};
} // namespace sdds
#endif