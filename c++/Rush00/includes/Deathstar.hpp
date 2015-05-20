#ifndef DEATHSTAR_HPP
# define DEATHSTAR_HPP

#include "starwars.hpp"
#include "Input.hpp"

class Deathstar
{
public:
	Deathstar(int maxX);
	Deathstar(void);
	~Deathstar();

	Deathstar	&operator=(Deathstar const &rhs);

	int			getHp(void) const;
	int			getMaxX(void) const;
	void		emergence(int);

private:
	int		_maxX;
	int		_hp;
};

std::ostream	&operator<<(std::ostream &o, Deathstar const &i);

#endif /* !DEATHSTAR */
