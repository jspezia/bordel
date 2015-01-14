/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 18:13:38 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/13 23:52:49 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>


class Base		{public: virtual ~Base(void){} };
class A: public Base {};
class B: public Base {};
class C: public Base {};

Base		*generate(void)
{
	int		nb;
	Base	*parent;

	nb = rand() % 3;
	if (nb == 0)
	{
		A *child = new A;
		parent = static_cast<Base *>(child);
		std::cout << "classe A build" << std::endl;
	}
	else if (nb == 1)
	{
		B *child = new B;
		parent = static_cast<Base *>(child);
		std::cout << "classe B build" << std::endl;
	}
	else {
		C *child = new C;
		parent = static_cast<Base *>(child);
		std::cout << "classe C build" << std::endl;
	}
	return (parent);
}


void		identify_from_pointer(Base *p)
{
	A		*a = dynamic_cast<A *>(p);
	B		*b = dynamic_cast<B *>(p);
	C		*c = dynamic_cast<C *>(p);
	if ( a != NULL) {
		std::cout << "A" << std::endl;
		return;
	}
	if ( b != NULL) {
		std::cout << "B" << std::endl;
		return;
	}
	if ( c != NULL) {
		std::cout << "C" << std::endl;
		return;
	}
	return;
}

void identify_from_reference(Base & p) {
	try {
		(void)dynamic_cast<A &> (p);
		std::cout << "A" << std::endl;
	} catch (std::exception) {
		try {
			(void)dynamic_cast<B &> (p);
			std::cout << "B" << std::endl;
		} catch (std::exception) {
			std::cout << "C" << std::endl;
		}
	}
}


int			main() {
	srand(time(NULL));

	Base	*test = generate();
	std::cout << "identify from pointer :" << std::endl;
	identify_from_pointer(test);
	std::cout << "identify from reference :" << std::endl;
	identify_from_reference(*test);
	return (0);
}











