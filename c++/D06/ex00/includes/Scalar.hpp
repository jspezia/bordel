/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 23:58:41 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/13 23:58:43 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALAR_H
# define SCALAR_H

# include <iostream>

class Scalar {

public:
	Scalar(const std::string &num);
	Scalar(Scalar const &src);
	~Scalar();
	double getVal() const;
	std::string const & getSpecial() const;

	Scalar & operator=(Scalar const &rhs);
	std::string toChar() const;
	std::string toInt() const;
	std::string toFloat() const;
	std::string toDouble() const;

private:
	Scalar();

private:
	long double		_val;
	std::string		_special;

public:
	static std::string const	_char[7];
	static int const			_index[7];

};

#endif
