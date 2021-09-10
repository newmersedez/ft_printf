#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*new_s;

	i = 0;
	len = ft_strlen(s);
	new_s = malloc(len + 1);
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = s[i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
