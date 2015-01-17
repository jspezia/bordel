#include "UsernameModule.hpp"
#include "gkrellm.hpp"
#include "Input.hpp"
#include "Sysctl.hpp"

void		terminal(void)
{
	UsernameModule	mod1(1, 1);
	Input			inst;

	inst.init();
	mod1.setInfo("fyadaba, fils de dictateur Nigerien");
	while(42)
	{
		clear();
		inst.manage();
		mod1.displayTerm();
		if (inst.getKey() == "Exit")
			break;
		refresh();
		usleep(DELAY);
	}
	inst.end();
}



int			main()
{
	Sysctl ctl;
	ctl.init();

	terminal();
	std::cout << ctl;
	return (0);
}
