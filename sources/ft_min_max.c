#include "../headers/ft_printf.h"

long long	ft_min(long long a, long long b)
{	
	if (a <= b)
		return (a);
	return (b);
}

long long	ft_max(long long a, long long b)
{	
	if (a >= b)
		return (a);
	return (b);
}
