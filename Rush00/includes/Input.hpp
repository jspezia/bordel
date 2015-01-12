#ifndef INPUT_H
# define INPUT_H

# include <iostream>

class Input {

public:
	Input();
	Input(Input const &src);
	~Input();
	std::string const & getKey() const;
	int getMaxX() const;
	int getMaxY() const;
	void init();
	void manage();
	void end();

	Input & operator=(Input const &rhs);

private:
	std::string _key;
	int _maxX;
	int _maxY;

	static int const _refKeys[6];
	static  std::string const _refName[6];

};

#endif
