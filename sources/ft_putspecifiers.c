#include "../headers/ft_printf.h"

static t_format	ft_create_print_format(void)
{
	t_format	print_format;

	print_format.flags.minus = 0;
	print_format.flags.zero = 0;
	print_format.precision = -1;
	print_format.width = 0;
	print_format.type = 0;
	return (print_format);
}

static int	ft_fill_print_format(char *format, va_list *argc,
				t_format *print_format, int *error)
{
	int	offset;

	offset = 0;
	if (!format || !argc || !print_format || !error)
		return (-1);
	if (ft_fill_flags(format + offset, print_format, &offset) == -1)
		*error = -1;
	if (ft_fill_width(format + offset, argc, print_format, &offset) == -1)
		*error = -1;
	if (ft_fill_precision(format + offset, argc, print_format, &offset) == -1)
		*error = -1;
	if (ft_fill_specifiers(format + offset, print_format, &offset) == -1)
		*error = -1;
	return (offset);
}

static int	ft_output_incorrect_format(char *format, int offset)
{
	int	i;

	i = 0;
	ft_putchar('%');
	while (i < offset)
	{
		ft_putchar(*(format + i));
		i++;
	}
	return (i);
}

int	ft_putspecifiers(char **format, va_list *argc)
{
	t_format	print_format;
	int			error;
	int			offset;
	int			count;

	if (!format || !*format || !argc)
		return (-1);
	error = 0;
	count = 0;
	(*format)++;
	print_format = ft_create_print_format();
	offset = ft_fill_print_format(*format, argc, &print_format, &error);
	if (error == -1)
		count = ft_output_incorrect_format(*format, offset);
	else
		count = ft_output_specifiers(argc, &print_format);
	*format += offset;
	return (count);
}
