/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t01.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 09:38:32 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/06 09:49:54 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class			Student
{
	private:
		std::string _login;
	public:
		Student(std::string login) : _login(login)
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
	Student		bob = Student("bob42");
	Student*	jim = new Student("jim42");

	delete jim;

	return (0);
}
