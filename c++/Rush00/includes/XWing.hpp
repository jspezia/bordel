#ifndef XWING_HPP
# define XWING_HPP

# include "AFighter.hpp"
# include "Input.hpp"
#include "Projectile.hpp"

class XWing : public AFighter {

public:
	XWing(std::string const &weapon, int hp, int x, int y, int speed);
	XWing(XWing const &src);
	~XWing();
	void		shoot(Input &inst);

	XWing & operator=(XWing const &rhs);

	bool		move(Input &inst);
	void		displayInfo();
	virtual int 		checkCollision(int x, int y);

protected:
	XWing();
	Projectile		*_projectile[5];
	
};

std::ostream & operator<<(std::ostream &o, XWing const &i);

#endif
