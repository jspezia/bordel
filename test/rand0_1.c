#include "libft.h"
#include <unistd.h>
#include <time.h>

int		main(void)
{
	int		i;

	srand(time(NULL));
	i = rand();
	ft_putnbr(i);
	ft_putchar('\n');
	ft_putnbr((i % 2));
	ft_putchar('\n');
	return (0);
}
