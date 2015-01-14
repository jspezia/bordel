/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:59:15 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/14 00:02:34 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <sstream>
#include "Scalar.hpp"

static bool isNumber(std::string const &nb) {
	if (!isdigit(nb[0]) && nb[0] != '-' && nb[0] != '+')
		return false;
	for (unsigned int i = 1; i < nb.size(); i++)
		if (!isdigit(nb[i]))
			return false;
	return true;
}

static bool checkChar(std::string &nbr) {
	if ((nbr.size() != 1 && nbr.size() != 2) || isdigit(nbr[0]))
		return false;
	int b;
	if (nbr.size() == 2) {
		bool flag = false;
		for (int i = 0; i < 7; i++) {
			if (nbr == Scalar::_char[i]) {
				b = Scalar::_index[i];
				flag = true;
			}
		}
		if (!flag)
			return false;
	}
	if (nbr.size() == 1) {
		char c = nbr[0];
		std::string str = "";
		str.push_back(c);
		std::istringstream ss(str);
		char a;
		ss >> a;
		b = static_cast<int>(a);
	}
	std::ostringstream o;
	o << b;
	nbr = o.str();
	return true;
}

static void checkVal(std::string &nbr) {
	if (nbr == "nan" || nbr == "nanf" || nbr == "+inf" || nbr == "-inf"
			|| nbr == "+inff" || nbr == "-inff")
		return;
	if (nbr.size() &&  nbr[nbr.size() - 1] == 'f') {
		nbr = nbr.substr(0, nbr.size() - 1);
	}
	size_t pos;
	if ((pos = nbr.find(".")) != std::string::npos) {
		std::string s1 = nbr.substr(0, pos);
		std::string s2 = nbr.substr(pos + 1);
		if (!isNumber(s1) || !isNumber(s2))
			nbr = "nan";
	}
	else if (!isNumber(nbr))
		nbr = "nan";
}

int main(int ac, char **av) {
	if (ac == 2) {
		std::string input(av[1]);
		if (!checkChar(input))
			checkVal(input);
		Scalar conv(input);
		std::cout << conv.toChar() << std::endl
			<< conv.toInt() << std::endl
			<< conv.toFloat() << std::endl
			<< conv.toDouble() << std::endl;
	}
	return 0;
}
