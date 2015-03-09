#include "libft.h"
#include <stdlib.h>

char	hjtrs(char c)
{
	if (c == 's' || c == 'r' || c == 't' || c == 'j' || c == 'h')
		return (c);
	if (c < 'U')
		return (c + 42);
	return (c - 42);
}

char	*srtjh(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (*str)
		ret[i++] = hjtrs(*str++);
	ret[i] = '\0';
	return (ret);
}

int		main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	ft_putendl(srtjh(av[1]));
	return (0);
}
