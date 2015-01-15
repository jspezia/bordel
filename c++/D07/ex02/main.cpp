/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:10:40 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/14 18:10:42 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template<typename T>
static void affTab(Array<T> &tab) {
	unsigned int a = tab.size();
	std::cout << "tab size: " << a << std::endl;
	for (unsigned int i = 0; i < a; i++)
		std::cout << "tab[" << i << "]: " << tab[i] << std::endl;
}

int main() {
	std::cout << "Creating an Array of int:" << std::endl;
	Array<int> tab(3);
	::affTab(tab);
	std::cout << "Filling the Array of int:" << std::endl;
	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	::affTab(tab);
	try {
		std::cout << "Trying to access out of range element at position 4:" << std::endl;
		std::cout << tab[4] << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "received exception out of range !" << std::endl;
	}
	Array<float> tab2(5);
	tab2[0] = 3.14;
	tab2[1] = 22.27;
	tab2[2] = 42.42;
	tab2[3] = 0.009;
	tab2[4] = 2015.01;
	std::cout << "Creating an Array of float using the copy constructor:" << std::endl;
	Array<float> tab3(tab2);
	::affTab(tab3);
	return 0;
}
