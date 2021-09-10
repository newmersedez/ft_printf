#include "../headers/ft_printf.h"

int	ft_putstr(char *str, int precision)
{
	int	count;

	if (precision >= (int)ft_strlen(str))
	{
		ft_putstr_fd(str, 1);
		count = ft_strlen(str);
	}
	else
	{
		count = 0;
		while (str[count] && count < precision)
		{
			ft_putchar_fd(str[count], 1);
			count++;
		}
	}
	return (count);
}
