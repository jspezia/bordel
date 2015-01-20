#ifndef SYSCTL_H
# define SYSCTL_H

# include <iostream>
# include <map>

typedef std::map<std::string, std::string> smap;

class Sysctl {

public:
	Sysctl(int ac, char **av);
	Sysctl(Sysctl const &src);
	~Sysctl();
	int	getAC() const;
	char ** getAV() const;
	smap * getData() const;
	std::string const &getData(std::string const &key) const;
	void init();

	Sysctl & operator=(Sysctl const &rhs);

private:
	int		_ac;
	char	**_av;
	smap	*_data;
	static std::string const _keys[3];

	Sysctl();

};

std::ostream & operator<<(std::ostream &o, Sysctl const &i);

#endif
