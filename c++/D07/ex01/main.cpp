#include <iostream>

template<typename T>
void		fct(T &c)
{
	std::cout << c;
	c += 4;
}

template<typename T, typename U, typename V>
void iter(T &str, U length, V ptr)
{
	for (U i = 0; i < length; i++)
		ptr(str[i]);
}

int			main()
{
	int		arr[4] = {1, 2, 3, 4};
	char	str[] = "hello";

	::iter(arr, 4, &fct<int>);
	std::cout << "    ";
	std::cout << arr[0];
	std::cout << std::endl;

	::iter(str, 5, &fct<char>);
	std::cout << "   ";
	std::cout << str[0];
	std::cout << std::endl;

	return (0);
}
