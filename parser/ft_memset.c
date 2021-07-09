#include "../headers/minirt.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	sim;

	i = 0;
	str = (unsigned char*)b;
	sim = (unsigned char)c;
	while (i < len)
	{
		str[i] = sim;
		i++;
	}
	return (str);
}
