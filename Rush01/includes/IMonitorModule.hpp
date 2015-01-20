#ifndef IMONTOR_MODULE_HPP
# define IMONTOR_MODULE_HPP

#include "gkrellm.hpp"

class IMonitorModule
{
	public:
		virtual ~IMonitorModule(void) {};
		virtual int				getX(void) const = 0;
		virtual int				getY(void) const = 0;
		virtual std::string		getInfo(void) const = 0;
		virtual void			update(void) = 0;
//		virtual void			display(void) = 0;
		virtual void displayTerm(void) = 0;
};

#endif /* ! IMONTOR_MODULE_HPP */
