#include "../headers/ft_printf.h"

int	ft_fill_specifiers(char *format,
		t_format *print_format, int *offset)
{
	if (!format || !print_format)
		return (-1);
	if (!ft_is_specifier(*format))
		return (-1);
	else
	{
		print_format->type = *format;
		format++;
		(*offset)++;
	}
	return (0);
}
