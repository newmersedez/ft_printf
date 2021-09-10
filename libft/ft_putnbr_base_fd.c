#include "../headers/ft_printf.h"

void 	ft_putnbr_base_fd(long long n, int base, int fd)
{
	char	c;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_base_fd(-n, fd);
	}
	else if (n >= 10)
	{
		c = (n % 10) + '0';
		ft_putnbr_base_fd(n / 10, fd);
		ft_putchar_fd(c, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
