#ifndef TODO_MODULE_HPP
#define TODO_MODULE_HPP

#include "gkrellm.hpp"
#include "IMonitorModule.hpp"

class TodoModule : public IMonitorModule
{
public:
	TodoModule(int x, int y);
	TodoModule(std::string name);
	~TodoModule(void);

	void			setInfo(std::string const info);
	std::string		getInfo(void) const;
	int				getX(void) const;
	int				getY(void) const;
	void			update(void);
	void			displayTerm(void);


protected:
	TodoModule(void);
	TodoModule(TodoModule &src);
	TodoModule			operator=(TodoModule &rhs);


private:
	std::string	_info;
	int			_x;
	int			_y;
};

#endif /* !TODO_MODULE_HPP */
