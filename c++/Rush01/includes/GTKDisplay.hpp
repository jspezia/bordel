#ifndef GTKDISPLAY_H
# define GTKDISPLAY_H

# include <iostream>
# include <gtk/gtk.h>
# include "IMonitorDisplay.hpp"
# include "Sysctl.hpp"

class GTKDisplay : public IMonitorDisplay {

public:
	GTKDisplay(Sysctl *ctl);
	~GTKDisplay();
	void display(mlist &target);

private:
	Sysctl	*_ctl;

	GTKDisplay();
	GTKDisplay(GTKDisplay const &);

	GTKDisplay & operator=(GTKDisplay const &);

};

#endif
