#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_temp;
	unsigned char	*dest_temp;

	if (!dest && !src)
		return (NULL);
	i = 0;
	src_temp = (unsigned char *)src;
	dest_temp = (unsigned char *)dest;
	while (i < n)
	{
		dest_temp[i] = src_temp[i];
		if (src_temp[i] == (unsigned char)c)
			return ((unsigned char *)dest + i + 1);
		i++;
	}
	return (NULL);
}
