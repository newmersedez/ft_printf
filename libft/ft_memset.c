#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	symbol;

	i = 0;
	ptr = (unsigned char *)b;
	symbol = (unsigned char)c;
	while (i < len)
	{
		*(ptr + i) = symbol;
		i++;
	}
	return (b);
}
