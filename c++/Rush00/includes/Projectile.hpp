#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "MapObject.hpp"

class Projectile : public MapObject
{
	public:
		Projectile(int x, int y, int speed, std::string look, bool right);
		Projectile(Projectile const &src);
		virtual ~Projectile();

		Projectile		&operator=(Projectile const &rhs);

		int				getDmg(void) const;
		bool			getRight(void) const;
		void			setRight(bool const right);

	Projectile(void);

	protected:
		bool	_right;
		int		_dmg;
};

#endif /* !PROJECTILE_HPP */
