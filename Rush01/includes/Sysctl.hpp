#ifndef SYSCTL_H
# define SYSCTL_H

# include <iostream>
# include <map>

typedef std::map<std::string, std::string> smap;

class Sysctl {

public:
	Sysctl();
	Sysctl(Sysctl const &src);
	~Sysctl();
	smap * getData() const;
	std::string const &getData(std::string const &key) const;
	void init();

	Sysctl & operator=(Sysctl const &rhs);

private:
	smap	*_data;
	static std::string const _keys[3];

};

std::ostream & operator<<(std::ostream &o, Sysctl const &i);

#endif
