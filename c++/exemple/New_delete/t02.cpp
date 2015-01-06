/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 09:38:32 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 09:51:41 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class			Student
{
	private:
		std::string _login;
	public:
		Student() : _login("default")
	{
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}
	~Student()
	{
		std::cout << "Student " << this->_login << " is died" << std::endl;
	}
};

int				main()
{
	Student*	jim = new Student[42];

	delete [] jim;

	return (0);
}
