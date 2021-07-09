#include "../headers/get_next_line.h"

char		*ft_strchr(char *s)
{
	while (*s != '\0')
	{
		if (*s == '\n')
			return ((char*)s);
		s++;
	}
	return (NULL);
}

void		*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = malloc(count * size)))
		return (0);
	else
	{
		i = 0;
		while (i < size)
		{
			str[i] = '\0';
			i++;
		}
		return ((void *)str);
	}
}

int			ft_strlenn(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(char *s1)
{
	int		i;
	char	*s2;

	i = 0;
	while (s1[i] != '\0')
		i++;
	if (!(s2 = ft_calloc((i + 1), sizeof(char))))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char		*ft_strjoin_f(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	if (!(str = ft_calloc(ft_strlenn(s1) + ft_strlenn(s2) + 1, sizeof(char))))
		return (0);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}
