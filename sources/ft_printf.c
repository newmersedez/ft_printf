#include "../headers/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	argc;
	int		count;
	int		printed;

	if (!format)
		return (-1);
	count = 0;
	va_start(argc, format);
	while (*format != '\0')
	{
		if (*format != '%')
			printed = ft_putchar(*(format++));
		else
			printed = ft_putspecifiers((char **)&format, &argc);
		if (printed == -1)
			return (-1);
		count += printed;
	}
	va_end(argc);
	return (count);
}
