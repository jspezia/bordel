#include "TodoModule.hpp"
#include "gkrellm.hpp"
#include "Input.hpp"
#include "Sysctl.hpp"
#include "GTKDisplay.hpp"
#include "TimeModule.hpp"
#include "NCDisplay.hpp"
#include "IMonitorDisplay.hpp"

int			main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "usage: " << av[0]
			<< " [mode] (console / window)." << std::endl;
		return 1;
	}

	Sysctl ctl(ac, av);
	ctl.init();

	TodoModule		mod1(3, 1);
	TodoModule		mod2(7, 1);
	TodoModule		mod3(11, 1);
	TimeModule		mod4(3, 30);
	mlist			lst;

	mod1.setInfo(ctl.getData("hostname"));
	mod2.setInfo(ctl.getData("osrelease"));
	mod3.setInfo(ctl.getData("ostype"));
	lst.push_back(&mod1);
	lst.push_back(&mod2);
	lst.push_back(&mod3);
	lst.push_back(&mod4);

	std::string mode = av[1];
	if (mode == "console") {
		NCDisplay		dplay;
		Input			inst;

		inst.init();
		while(42)
		{
			clear();
			inst.manage();
			dplay.display(lst);
			if (inst.getKey() == "Exit")
				break;
			refresh();
			usleep(DELAY);
		}
		inst.end();
	}
	else if (mode == "window") {
		GTKDisplay test(&ctl);

		mod4.update();
		test.display(lst);
	}
	return (0);
}
