#ifndef NCDISPLAY_H
# define NCDISPLAY_H

# include "gkrellm.hpp"
# include "IMonitorDisplay.hpp"

class NCDisplay : IMonitorDisplay {

public:
	NCDisplay();
	~NCDisplay();
	void		display(mlist &targets);

private:
	NCDisplay(NCDisplay const &);

	NCDisplay & operator=(NCDisplay const &);

};

#endif
