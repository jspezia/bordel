#include <stdexcept>
#include <iostream>

template<typename T>
Array<T>::Array() : _tab(new T[0]), _size(0) {
}

template<typename T>
Array<T>::Array(unsigned int n) : _tab(new T[n]), _size(n) {
}

template<typename T>
Array<T>::Array(Array const &src) {
	*this = src;
}

template<typename T>
Array<T>::~Array() {
}

template<typename T>
unsigned int Array<T>::size() const {
	return this->_size;
}

template<typename T>
Array<T> & Array<T>::operator=(Array const &rhs) {
	if (this != &rhs) {
		this->_size = rhs.size();
		this->_tab = new T[rhs.size()];
		for (unsigned int i = 0; i < rhs.size(); i++)
			this->_tab[i] = rhs[i];
	}
	return *this;
}

template<typename T>
T & Array<T>::operator[](int index) const {
	if (index < 0 || index >= this->_size)
		throw std::exception();
	return this->_tab[index];
}

