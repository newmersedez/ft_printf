#include "../headers/ft_printf.h"

int	ft_output_zeros(int a)
{
	int	i;

	if (a < 0)
		return (0);
	i = 0;
	while (i < a)
	{
		ft_putchar('0');
		i++;
	}
	return (i);
}
