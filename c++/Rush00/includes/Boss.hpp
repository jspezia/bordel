#ifndef BOSS_HPP
# define BOSS_HPP

#include <iostream>
#include "Input.hpp"
#include "starwars.hpp"

class Boss
{

public:

	Boss();
	Boss(Boss const &src);
	~Boss();
	std::string		getStr(void) const;

	Boss		&operator=(Boss const &rhs);

//	void		show(Input &inst);
//	void		duel(XWing luke, Input &inst);


private:

	std::string		_str;
};


#endif /* !BOSS_HPP */
