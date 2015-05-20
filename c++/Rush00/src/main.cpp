#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "starwars.hpp"
#include "Input.hpp"
#include "Map.hpp"
#include "XWing.hpp"
#include "Projectile.hpp"
#include "Deathstar.hpp"

int	g_refTime = 0;
e_game g_status = PLAY;
//std::ofstream g_ofs("pos.debug");

void			ft_test(Input &inst, int i)
{
	std::ostringstream		ss;

	ss << i;
	std::string str = ss.str();
	mvprintw(FLOOR + 3, 0, "Score: ");
	mvprintw(FLOOR + 3, 6, str.c_str());
	mvprintw(FLOOR + 3, inst.getMaxY() - 20, "BOSS - 500 pts");
	return;
}

void		ft_intro(Input inst)
{
	std::ifstream		read("assets/intro.txt");
	std::ifstream		read2("assets/intro2.txt");
	std::string		line;
	std::string		all;

	int		xmax;
	xmax = inst.getMaxX();

	if (read2.is_open())
	{
		while(std::getline(read2, line))
			all += line + '\n';
	}
	int		i = 0;
	while(i != 2)
	{
		clear();
		mvprintw(5, 0, all.c_str());
		inst.manage();
		refresh();
		sleep(1);
		i++;
	}

	all = "";

	if (read.is_open())
	{
		while(std::getline(read, line))
			all += line + '\n';
	}
	while(xmax != -4)
	{
		clear();
		mvprintw(xmax + 1, 0, all.c_str());
		inst.manage();
		refresh();
		usleep(150000);
		xmax--;
	}
	sleep(1);

}


void			ft_end(Input &inst)
{
	std::ifstream		read("assets/end.txt");
	std::string		line;
	std::string		all;

	int				xmax;
	xmax = inst.getMaxX();

	if (read.is_open())
	{
		while(std::getline(read, line))
			all += line + '\n';
	}
	while(xmax != -4)
	{
		clear();
		mvprintw(xmax + 1, 0, all.c_str());
		inst.manage();
		refresh();
		usleep(50000);
		xmax--;
	}
}


void		ft_display(Input &inst, int time, std::string fileName,
		int posX, int posY)
{
	std::ifstream		read(fileName.c_str());
	std::string		line;
	std::string		all;

	if (read.is_open())
	{
		while(std::getline(read, line))
			all += line + '\n';
	}
	while(time != 0)
	{
		clear();
		mvprintw(posX, posY, all.c_str());
		inst.manage();
		refresh();
		usleep(500000);
		time--;
	}
}



int				main()
{
	Input		inst;
	inst.init();

//	ft_intro(inst);

	Projectile		test(20, 20, 10, "-", true);

	XWing	luke("Laser", 5, 15, 15, 0);
	Map		map(&luke, CEILING, FLOOR, inst.getMaxY());
	int		i = 0;
	int		oldTime(0);

	Deathstar	DA1(inst.getMaxY());

	std::srand(std::time(NULL));
	map.addEnemy();
	while (42)
	{
		clear();
		inst.manage();
		ft_test(inst, i);
		i++;
		if (!(luke.move(inst)))
			map.setStatus(DEATH);
		map.updateXWingPos(luke);
		luke.display();
		luke.displayInfo();
		g_refTime = i / 10;
		if (g_refTime > oldTime) {
			map.addEnemy();
			oldTime = g_refTime;
		}
//		if (map.getStatus() == DEATH) {
//			g_ofs.close();
//			inst.end();
//			return 0;
//		}
		if (i == 500)
		{
			luke.setPosX(15);
			luke.setPosY(15);
			i = 0;
			while (i != 15)
			{
				clear();
				inst.manage();
				DA1.emergence(i);
				luke.display();
				refresh();
				usleep(300000);
				i++;
			}
			while (42)
			{
				ft_display(inst, 1,  "assets/choice.txt", 10, 10);
				if (inst.getKey() == "Left")
				{
					ft_end(inst);
					inst.end();
					return (0);
				}
				if(inst.getKey() == "Right")
				{
					ft_display(inst, 5,  "assets/DS2.txt", 0, 15);
					ft_display(inst, 10,  "assets/DS3.txt", 0, 10);
					inst.end();
					return (0);
				}
			}
		}
		if (g_status == DEATH)
		{
			if (luke.getShield() == 0)
				break;
			else
			{
				luke.setShield(luke.getShield() - 1);
				g_status = PLAY;
			}
		}
		map.display();
		map++;
		refresh();
		usleep(DELAY);
		if (inst.getKey() == "Exit")
			break;
	}
	inst.end();
	return (0);
}
