
#ifndef UNIT_CLASS_HPP
# define UNIT_CLASS_HPP
#include <iostream>
#include <string>


class Unit
{

	public:
		Unit(void);
		~Unit(void);
		Unit(Unit const &src);
		Unit(std::string type, int x, int y, int dam, int chp, int mhp);
		Unit		&operator=(Unit const &rhs);

		int			getIndex(void) const;
		std::string	getType(void) const;
		int			getX(void) const;
		int			getY(void) const;
		int			getDam(void) const;
		int			getCHP(void) const;
		int			getMHP(void) const;
		void		die(void);
		void		move(int x, int y);
		void		attack(Unit &target) const;
		void		setCHP(int i);

	protected:

	private:
		int			_index;
		std::string	_type;
		int			_x;
		int			_y;
		int			_dam;
		int			_chp;
		int			_mhp;

};


std::ostream		&operator<<(std::ostream &o, const Unit &i);
void				operator+=(Unit &o, int i);
void				operator-=(Unit &o, int i);

#endif /* !UNIT_CLASS_HPP */
