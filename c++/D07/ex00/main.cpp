#include <iostream>

template<typename T>
void swap(T &arg1, T &arg2) {
	T tmp;
	tmp = arg1;
	arg1 = arg2;
	arg2 = tmp;
}

template<typename T>
T const & min(T const &arg1, T const &arg2) {
	return (arg2 <= arg1) ? arg2 : arg1;
}

template<typename T>
T const & max(T const &arg1, T const &arg2) {
	return (arg2 >= arg1) ? arg2 : arg1;
}

int main( void ) {
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	return 0;
}

