
#ifndef STARWARS_HPP
# define STARWARS_HPP

# define DELAY		50000
# define CEILING	5
# define FLOOR		35

# include <iostream>
# include <sstream>
# include <fstream>
# include <cstdlib>
# include <ncurses.h>
# include "MapObject.hpp"

enum e_game {
	PLAY,
	DEATH,
	WIN,
	LOSE
};

#endif /* !STARWARS_HPP */
