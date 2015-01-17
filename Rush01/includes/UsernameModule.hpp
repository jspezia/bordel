#ifndef USER_MODULE_HPP
#define USER_MODULE_HPP

#include "gkrellm.hpp"
#include "IMonitorModule.hpp"

class UsernameModule : public IMonitorModule
{
public:
	UsernameModule(int x, int y);
	UsernameModule(std::string name);
	~UsernameModule(void);

	void			setInfo(std::string const info);
	std::string		getInfo(void) const;
	int				getX(void) const;
	int				getY(void) const;
	void			update(void);
	void			displayTerm(void);


protected:
	UsernameModule(void);
	UsernameModule(UsernameModule &src);
	UsernameModule			operator=(UsernameModule &rhs);


private:
	std::string	_info;
	int			_x;
	int			_y;
};

#endif /* !USER_MODULE_HPP */
