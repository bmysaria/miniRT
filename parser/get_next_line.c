#include "../headers/get_next_line.h"

int					ft_line(char **line, char **newline, char *ptr)
{
	char *tmp;

	*ptr = '\0';
	tmp = *line;
	if (!(*line = ft_strdup(*line)))
		return (-1);
	ptr++;
	if (!(*newline = ft_strdup(ptr)))
		return (-1);
	free(tmp);
	return (1);
}

int					ft_end(char **line, char **newline)
{
	char *tmp;

	tmp = *line;
	if (!(*line = ft_strdup(*line)))
		return (-1);
	if (*line)
		free(tmp);
	*newline = NULL;
	return (0);
}

int					get_next_line(int fd, char **line)
{
	char			*ptr;
	char			buff[2];
	int				count;
	static char		*newline;

	if (read(fd, 0, 0) < 0)
		return (-1);
	if (newline)
		*line = newline;
	else if (!(*line = ft_calloc(1, sizeof(char))))
		return (-1);
	count = 1;
	while (!(ptr = ft_strchr(*line)))
	{
		if (count < 1)
			break ;
		count = read(fd, buff, 1);
		buff[count] = '\0';
		if (!(*line = ft_strjoin_f(*line, buff)))
			return (-1);
	}
	if (ptr)
		return (ft_line(line, &newline, ptr));
	return (ft_end(line, &newline));
}
