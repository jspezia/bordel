#include <unistd.h>
#include <ncurses.h>
#include "Input.hpp"

Input::Input() : _key("") {

}

Input::Input(Input const &src) {
	*this = src;
}

Input::~Input() {

}

std::string const & Input::getKey() const {
	return this->_key;
}

int Input::getMaxX() const {
	return this->_maxX;
}

int Input::getMaxY() const {
	return this->_maxY;
}

void Input::init() {
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
   	noecho();
	curs_set(FALSE);
	keypad(stdscr, true);
	nodelay(stdscr, true);
	getmaxyx(stdscr, this->_maxX, this->_maxY);
}

void Input::manage() {
	int ch = getch();
	for (int i = 0; i < 6; i++) {
		if (ch == Input::_refKeys[i]) {
			this->_key = Input::_refName[i];
			return;
		}
		else
			this->_key = "     ";
	}
}

void Input::end() {
	endwin();
}

Input & Input::operator=(Input const &rhs) {
	if (this != &rhs) {
		this->_key = rhs.getKey();
		this->_maxX = rhs.getMaxX();
		this->_maxY = rhs.getMaxY();
	}
	return *this;
}

const int Input::_refKeys[6]  = {
	KEY_UP,
	KEY_RIGHT,
	KEY_DOWN,
	KEY_LEFT,
	27,
	32
};

std::string const Input::_refName[6] = {
	"Up",
	"Right",
	"Down",
	"Left",
	"Exit",
	"Space"
};

