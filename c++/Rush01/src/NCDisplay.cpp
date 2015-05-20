#include "NCDisplay.hpp"
#include "gkrellm.hpp"

NCDisplay::NCDisplay() {
	return ;
}


NCDisplay::NCDisplay(NCDisplay const &) {
}

void			NCDisplay::display(mlist &targets)
{
	mlist::const_iterator		it;
	IMonitorModule *elm;

	for (it = targets.begin(); it != targets.end(); ++it)
	{
		elm = *it;
		elm->update();
		elm->displayTerm();
	}
}

NCDisplay::~NCDisplay() {
	return ;
}

NCDisplay & NCDisplay::operator=(NCDisplay const &) {
	return *this;
}
