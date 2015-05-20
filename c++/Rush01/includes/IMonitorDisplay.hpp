#ifndef IMONITOR_DISPLAY_H
# define IMONITOR_DISPLAY_H

#include <list>
#include "IMonitorModule.hpp"

typedef std::list<IMonitorModule *> mlist;

class IMonitorDisplay
{
	public:
		virtual ~IMonitorDisplay(void) {};
		virtual void display(mlist &targets) = 0;

};

#endif /* IMONITOR_DISPLAY_H */
