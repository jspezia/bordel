#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

int			main()
{
	char	*line;
	int		fd;
	int		fd2;
	int		fd3;
	int		diff;

	system("mkdir -p sandbox");
	system("openssl rand -out sandbox/1.txt -base64 $((50 * 1000 * 3/4))");
	line = NULL;
	fd = open("sandbox/1.txt", O_RDONLY);
	fd2 = open("sandbox/2.txt", O_CREAT | O_RDWR | O_TRUNC, 0755);
	while (get_next_line(fd, &line))
		ft_putendl_fd(line, fd2);
	if (line)
	{
		write(fd2, line, ft_strlen(line));
		ft_putendl(line);
	}
	close(fd);
	close(fd2);
	system("diff sandbox/1.txt sandbox/2.txt > sandbox/diff.txt");
	fd3 = open("sandbox/diff.txt", O_RDONLY);
	diff = read(fd3, NULL, 10);
	close(fd3);
	ft_putnbr(diff);

	return (0);
}
