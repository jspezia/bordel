#ifndef TIE_FIGHTER_H
# define TIE_FIGHTER_H

# include "AFighter.hpp"
#include "Input.hpp"

class TieFighter : public AFighter {

public:
	TieFighter(std::string const &weapon, int hp, int x, int y, int speed);
	TieFighter(TieFighter const &src);
	virtual ~TieFighter();
	void shoot(Input &i);
	virtual int		checkCollision(int x, int y);

	TieFighter & operator=(TieFighter const &rhs);

protected:
	TieFighter();

protected:
	bool _active;

};

std::ostream & operator<<(std::ostream &o, TieFighter const &i);

#endif
