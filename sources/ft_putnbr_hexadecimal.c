#include "../headers/ft_printf.h"

static char	*ft_get_hex(long long a, int *length)
{
	static char	hex[9];
	int			temp;
	int			i;

	i = 8;
	hex[9] = '\0';
	if (a == 0)
	{
		*length = 1;
		hex[8] = '0';
		return (hex);
	}
	while (a > 0)
	{
		temp = a % 16;
		if (temp < 10)
			hex[i] = temp + '0';
		else
			hex[i] = temp - 10 + 'a';
		a /= 16;
		i--;
	}
	i++;
	*length = 9 - i;
	return (hex);
}

static int	ft_print_lowercase(char *hex, int length)
{
	int	i;

	if (!hex)
		return (0);
	i = 9 - length;
	while (i < 9)
	{
		ft_putchar(hex[i]);
		i++;
	}
	return (length);
}

static int	ft_print_uppercase(char *hex, int length)
{
	int	i;

	if (!hex)
		return (0);
	i = 9 - length;
	while (i < 9)
	{
		if (ft_isdigit(hex[i]))
			ft_putchar(hex[i]);
		else
			ft_putchar(hex[i] - ('a' - 'A'));
		i++;
	}
	return (length);
}

int	ft_putnbr_hex_lowercase(long long a, int precision)
{
	int		count;
	int		length;
	char	*hex;

	count = 0;
	hex = NULL;
	if (precision == 0)
		return (0);
	else if (precision <= ft_numberlen(a))
	{
		hex = ft_get_hex(a, &length);
		if (hex)
			count += ft_print_lowercase(hex, length);
	}
	else
	{
		hex = ft_get_hex(a, &length);
		count += ft_output_zeros(precision - length);
		if (hex)
			count += ft_print_lowercase(hex, length);
	}
	return (count);
}

int	ft_putnbr_hex_uppercase(long long a, int precision)
{
	int		count;
	int		length;
	char	*hex;

	count = 0;
	hex = NULL;
	if (precision == 0)
		return (0);
	else if (precision <= ft_numberlen(a))
	{
		hex = ft_get_hex(a, &length);
		if (hex)
			count += ft_print_uppercase(hex, length);
	}
	else
	{
		hex = ft_get_hex(a, &length);
		count += ft_output_zeros(precision - length);
		if (hex)
			count += ft_print_uppercase(hex, length);
	}
	return (count);
}
