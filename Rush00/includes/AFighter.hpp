#ifndef AFIGHTER_H
# define AFIGHTER_H

# include "MapObject.hpp"
#include "Input.hpp"
# include <string>

class AFighter : public MapObject {

public:
	AFighter(std::string const &type, std::string const &weapon, int hp,
			int x, int y, int speed, std::string look);
	AFighter(AFighter const &src);
	virtual ~AFighter();
	std::string const & getType() const;
	std::string const & getWeapon() const;
	int		getShield() const;
	void	setShield(int const nb);
	int getMaxShield() const;
	virtual void shoot(Input &i) = 0;

	AFighter & operator=(AFighter const &rhs);

protected:
	AFighter();

protected:
	std::string		_type;
	std::string		_weapon;
	int				_shield;
	int				_maxShield;

};

std::ostream & operator<<(std::ostream &o, AFighter const &i);

#endif
