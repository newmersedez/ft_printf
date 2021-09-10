#include "../headers/ft_printf.h"

static char	*ft_get_hex(long long a, int *length)
{
	static char	hex[9];
	int			temp;
	int			i;

	i = 8;
	hex[9] = '\0';
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

static int	ft_putnbr_hex(char *hex, int length)
{
	int	i;

	if (!hex)
	{
		ft_putchar('0');
		return (1);
	}
	i = 9 - length;
	while (i < 9)
	{
		ft_putchar(hex[i]);
		i++;
	}
	return (length);
}

int	ft_putnbr_address(void *address, int precision)
{
	unsigned long long	a;
	int					count;
	int					length;
	char				*hex;

	count = 0;
	a = (unsigned long long)address;
	if (!address)
	{
		ft_putstr("(nil)", ft_strlen("(nil)"));
		return (0);
	}
	count += ft_putstr("0x", 2);
	if (precision <= ft_hexnumberlen(a))
	{
		hex = ft_get_hex(a, &length);
		count += ft_putnbr_hex(hex, length);
	}
	else
	{
		hex = ft_get_hex(a, &length);
		count += ft_output_zeros(precision - length);
		count += ft_putnbr_hex(hex, length);
	}
	return (count);
}

int	ft_output_address(t_format *print_format, void *address)
{
	int	count;

	if (!address)
		print_format->width = 0;
	if (print_format->flags.minus == 1)
	{
		count = ft_putnbr_address(address, print_format->precision);
		if (print_format->width > 0)
			count += ft_output_spaces(print_format->width - count);
	}
	else
	{
		if (print_format->precision > 0)
			print_format->flags.zero = 0;
		if (print_format->flags.zero == 1)
			count = ft_output_zeros(print_format->width - 2
					- ft_max(ft_hexnumberlen((unsigned long long)address),
						print_format->precision));
		else
			count = ft_output_spaces(print_format->width - 2
					- ft_max(ft_hexnumberlen((unsigned long long)address),
						print_format->precision));
		count += ft_putnbr_address(address, print_format->precision);
	}
	return (count);
}
