#include "../headers/ft_printf.h"

int	ft_putnbr_decimal(long long *a, int precision)
{
	int	count;

	count = 0;
	if (precision == 0)
		return (0);
	else if (precision <= ft_numberlen(*a))
		ft_putnbr_fd(*a, 1);
	else
	{
		if (*a < 0)
		{
			count += ft_putchar('-');
			*a = -(*a);
		}
		count += ft_output_zeros(precision - ft_numberlen(*a));
		ft_putnbr_fd(*a, 1);
	}
	count += ft_numberlen(*a);
	return (count);
}
