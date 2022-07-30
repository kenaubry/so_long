
#include "../includes/so_long.h"

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s && fd)
	{
		while (*s)
			ft_putchar_fd(*s++, fd);
		ft_putchar_fd('\n', fd);
	}
}
