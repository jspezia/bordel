/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspezia <jspezia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/14 00:00:54 by jspezia           #+#    #+#             */
/*   Updated: 2015/01/14 00:03:38 by jspezia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

struct Data {
	std::string		s1;
	int				n;
	std::string		s2;
};

void * serialize( void ) {
	std::string serial1("");
	std::string serial2("");
	for (int i = 0; i < 8; i++) {
		serial1.push_back(rand() % 95 + 32);
		serial2.push_back(rand() % 95 + 32);
	}
	int val = rand();
	std::cout << "serialize called and generated the following values (string1 int string2):" << std::endl
		<< serial1 << " " << val << " " << serial2 << std::endl;
	std::ostringstream ss;
	ss << val;
	std::string *ret = new std::string(serial1 + ss.str() + serial2);
	void *ptr = reinterpret_cast<void *>(ret);
	return ptr;
}

Data * deserialize( void * raw ) {
	std::cout << "deserialize called and decrypt the void * pointer received." << std::endl;
	std::string *str = reinterpret_cast<std::string *>(raw);
	std::string deserial1 = str->substr(0, 8);
	size_t pos = str->size() - 8;
	std::string nbr = str->substr(8, pos - 8);
	std::string deserial2 = str->substr(pos);
	Data *data = new Data;
	data->s1 = deserial1;
	std::istringstream ss(nbr);
	ss >> data->n;
	data->s2 = deserial2;
	return data;
}

int main() {
	srand(time(NULL));
	void *ptr = serialize();
	Data *res = deserialize(ptr);
	std::cout << "deserialization results (Data.s1 Data.n Data.s2):" << std::endl
		<< res->s1 << " " << res->n << " " << res->s2 << std::endl;
	return 0;
}
