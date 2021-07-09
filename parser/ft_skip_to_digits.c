#include "../headers/minirt.h"

int		ft_skip_to_digits(char **line)
{
	int	flag;

	flag = 0;
	if (**line == ',')
	{
		(*line)++;
		if (ft_isdigit(**line) || **line == '-')
			flag = 1;
	}
	while (**line != '\0' && **line == ' ')
		(*line)++;
	if (**line == '-')
		flag = 1;
	if (ft_isdigit(**line))
		flag = 1;
	if (flag == 0 && *line != '\0')
		error(-2, "improper digit/numerical value expected");
	return (0);
}
