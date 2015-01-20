#include "Sysctl.hpp"

Sysctl::Sysctl() {
}

Sysctl::Sysctl(int ac, char **av) : _ac(ac), _av(av), _data(new smap) {
}

Sysctl::Sysctl(Sysctl const &src) {
	*this = src;
}

Sysctl::~Sysctl() {
}

int	Sysctl::getAC() const {
	return this->_ac;
}

char ** Sysctl::getAV() const {
	return this->_av;
}

smap * Sysctl::getData() const {
	return this->_data;
}

std::string const & Sysctl::getData(std::string const &key) const {
	return ((*this->_data)[key]);
}

void Sysctl::init() {
	FILE		*in;
	char		buff[512];
	std::string	info, res;

	if(!(in = popen("/usr/sbin/sysctl -a", "r")))
		return;
	while(fgets(buff, sizeof(buff), in) != NULL) {
		info = buff;
		for (int i = 0; i < 3; i++) {
			if (info.find(Sysctl::_keys[i]) != std::string::npos) {
				size_t pos;
				if ((pos = info.find_last_of(" ", info.size() - 1)) != std::string::npos) {
					res = info.substr(pos + 1, info.size() - pos - 2);
					(*this->_data)[Sysctl::_keys[i]] = res;
				}
			}
		}
	}
	pclose(in);

}

Sysctl & Sysctl::operator=(Sysctl const &rhs) {
	if (this != &rhs) {
		this->_ac = rhs.getAC();
		this->_av = rhs.getAV();
		this->_data = rhs.getData();
	}
	return *this;
}

std::string const Sysctl::_keys[3] = {
	"hostname",
	"ostype",
	"osrelease",
};

std::ostream & operator<<(std::ostream &o, Sysctl const &i) {
	smap::iterator it;
	for (it = i.getData()->begin(); it != i.getData()->end(); it++)
		o << it->first << ": " << it->second << std::endl;
	return o;
}

