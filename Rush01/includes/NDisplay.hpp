#ifndef NDISPLAY_HPP
#define NDISPLAY_HPP

#include "gkrellm.hpp"

class NDisplay
{
public:
	NDisplay(void);
	NDisplay(std::string name);
	~NDisplay(void);

	std::string		getName(void) const;
	void			addQuote(std::string const quote);
	void			removeQuote(std::string const quote);
	void			display(void);

protected:
	NDisplay(NDisplay &src);
	NDisplay			operator=(NDisplay &rhs);


private:
	std::string					_name;
	std::list<std::string>		_quotes;
	int							_N;
};

#endif /* !NDISPLAY_HPP */
