#include "libft.h"

void 	ft_putnbr_fd(long long n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2", fd);
		ft_putnbr_fd(147483648, fd);
	}
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		c = (n % 10) + '0';
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(c, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
