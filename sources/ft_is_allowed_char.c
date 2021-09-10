#include "../headers/ft_printf.h"

int	ft_is_allowed_char(char c)
{
	return (c == '-' || c == '0' || c == '*'
		|| c == '.' || ft_isdigit(c) || ft_is_specifier(c));
}
