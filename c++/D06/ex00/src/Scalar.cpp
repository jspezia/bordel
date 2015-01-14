/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:59:01 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/13 23:59:08 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <limits>
#include "Scalar.hpp"

Scalar::Scalar() {
}

Scalar::Scalar(const std::string &num) : _val(0), _special("") {
	if (num == "nan" || num == "nanf")
		this->_special = "nan";
	if (num == "-inf" || num == "-inff")
		this->_special = "-inf";
	else if (num == "+inf" || num == "+inff")
		this->_special = "+inf";
	else {
		std::istringstream ss(num);
		ss >> this->_val;
	}
}

Scalar::Scalar(Scalar const &src) {
	*this = src;
}

Scalar::~Scalar() {
}

double Scalar::getVal() const {
	return this->_val;
}

std::string const & Scalar::getSpecial() const {
	return this->_special;
}

std::string Scalar::toChar() const {
	if (this->_special != "")
		return "char: impossible";
	else {
		long int n = static_cast<long int>(this->_val);
		if (n < 0 || n < std::numeric_limits<char>::min()
				|| n > std::numeric_limits<char>::max())
			return "char: impossible";
		for (int i = 0; i < 7; i++) {
			if (n == Scalar::_index[i])
				return "char: '" + Scalar::_char[i] + "'";
		}
		if ((n >= 0 && n < 32) || n == 127)
			return "char: impossible";
		std::ostringstream ss;
		ss <<  static_cast<char>(this->_val);
		return "char: '" + ss.str() + "'";
	}
}

std::string Scalar::toInt() const {
	if (this->_special != "")
		return "int: impossible";
	else {
		long int n = static_cast<long int>(this->_val);
		if (n < std::numeric_limits<int>::min()
				|| n > std::numeric_limits<int>::max())
			return "int: impossible";
		std::ostringstream ss;
		ss <<  static_cast<int>(this->_val);
		return "int : " + ss.str();
	}
}

std::string Scalar::toFloat() const {
	if (this->_special != "")
		return "float: " + this->_special + "f";
	else {
		long double n = this->_val;
		if (n < -(std::numeric_limits<float>::max()))
			return "float: -inff";
		else if (n > std::numeric_limits<float>::max())
			return "float: +inff";
		std::ostringstream ss;
		ss <<  static_cast<float>(this->_val);
		std::string res = (ss.str().find(".") != std::string::npos)
			? ss.str() : ss.str() + ".0";
		return "float: " + res + "f";
	}
}
	
std::string Scalar::toDouble() const {
	if (this->_special != "")
		return "double: " + this->_special;
	else {
		long double n = this->_val;
		if (n < -(std::numeric_limits<double>::max()))
			return "double: -inf";
		else if (n > std::numeric_limits<double>::max())
			return "double: +inf";
		std::ostringstream ss;
		ss <<  static_cast<double>(this->_val);
		std::string res = (ss.str().find(".") != std::string::npos)
			? ss.str() : ss.str() + ".0";
		return "double : " + res;
	}
}

Scalar & Scalar::operator=(Scalar const &rhs) {
	if (this != &rhs) {
		this->_val = rhs.getVal();
		this->_special = rhs.getSpecial();
	}
	return *this;
}

std::string const Scalar::_char[7] = {
	"\\0", "\\a", "\\b", "\\t", "\\f", "\\n", "\\r"
};

int const Scalar::_index[7] = {
	0, 7, 8, 9, 12, 10, 13
};
