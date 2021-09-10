#include "../headers/ft_printf.h"

int	ft_numberlen(long long a)
{
	int	length;

	length = 0;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		length = 1;
		a = -a;
	}
	while (a > 0)
	{
		length++;
		a /= 10;
	}
	return (length);
}

int	ft_hexnumberlen(long long a)
{
	int	length;

	length = 0;
	if (a == 0)
		return (1);
	if (a < 0)
	{
		length = 1;
		a = -a;
	}
	while (a > 0)
	{
		a /= 16;
		length++;
	}
	return (length);
}
