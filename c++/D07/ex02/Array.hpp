/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 18:11:04 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/14 18:11:09 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

template<typename T>
class Array {

public:
	Array();
	Array(unsigned int n);
	Array(Array const &src);
	~Array();
	unsigned int size() const;

	Array & operator=(Array const &rhs);
	T & operator[](int index) const;

private:
	T				*_tab;
	unsigned int	_size;

};

#include "Array.hxx"
#endif
