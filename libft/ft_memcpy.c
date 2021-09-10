#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
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
		i++;
	}
	return (dest);
}
