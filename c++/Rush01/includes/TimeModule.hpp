#ifndef TIME_MODULE_HPP
#define TIME_MODULE_HPP

#include "gkrellm.hpp"
#include "IMonitorModule.hpp"

class TimeModule : public IMonitorModule
{
public:
	TimeModule(int x, int y);
	TimeModule(std::string name);
	~TimeModule(void);

	std::string		getInfo(void) const;
	int				getX(void) const;
	int				getY(void) const;
	void			update(void);
	void			displayTerm(void);


protected:
	TimeModule(void);
	TimeModule(TimeModule &src);
	TimeModule			operator=(TimeModule &rhs);


private:
	std::string	_info;
	int			_x;
	int			_y;
};

#endif /* !TIME_MODULE_HPP */
