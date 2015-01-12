#ifndef MAP_OBJECT_H
# define MAP_OBJECT_H

# include <iostream>

class MapObject {

public:
	MapObject(int x, int y, int speed, std::string look);
	MapObject(MapObject const &src);
	virtual ~MapObject();
	int getPosX() const;
	void setPosX(const int nb);
	int getPosY() const;
	void setPosY(const int nb);
	int getSpeed() const;
	bool moveX(int val);
	bool moveY(int val, int width);
	void display() const;
	virtual int checkCollision(int x, int y);

	MapObject & operator=(MapObject const &rhs);

protected:
	MapObject();

protected:
	int			_posX;
	int			_posY;
	int			_speed;
	std::string	_look;

};

std::ostream & operator<<(std::ostream &o, MapObject const &i);

#endif
