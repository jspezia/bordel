/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t03.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 10:39:16 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 10:52:47 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class Student
{
	private:
		std::string _login;

	public:
		Student(std::string const &login) : _login(login)
	{
	}

	std::string		&getLoginRef()
	{
		return this->_login;
	}
	std::string	const &getLoginRefConst() const
	{
		return this->_login;
	}

	std::string*	getLoginPtr()
	{
		return &(this->_login);
	}

	std::string		const * getLoginPtrConst() const
	{
		return &(this->_login);
	}
};

int		main()
{
	Student			bob = Student("bob");
	Student const	jim = Student("jim");

	std::cout << bob.getLoginRefConst() << " " << jim.getLoginRefConst() << std::endl;
	std::cout << *(bob.getLoginPtrConst()) << " " << *(jim.getLoginPtrConst()) << std::endl;

	bob.getLoginRef() = "bobi";
	std::cout << bob.getLoginRefConst() << std::endl;

	*(bob.getLoginPtr()) = "BOB";
	std::cout << bob.getLoginRefConst() << std::endl;

	return (0);
}
