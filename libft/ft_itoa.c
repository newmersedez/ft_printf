#include "libft.h"

static size_t	ft_numberlen(int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*number_str;		

	len = ft_numberlen(n);
	number_str = (char *)malloc(len + 1);
	if (!number_str)
		return (NULL);
	number_str[len--] = '\0';
	if (n == 0)
	{
		number_str[0] = '0';
		return (number_str);
	}
	if (n < 0)
		number_str[0] = '-';
	while (n != 0)
	{
		number_str[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	return (number_str);
}
