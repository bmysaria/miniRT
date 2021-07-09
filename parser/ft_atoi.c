#include "../headers/minirt.h"

int	ft_atoi(char **line)
{
	int a;
	int mn;
	int flag;
	int k;

	a = 0;
	mn = 1;
	flag = 0;
	k = 1;
	ft_skip_to_digits(line);
	if (**line == '-')
		mn = -1;
	if (**line == '-' || **line == '+')
		(*line)++;
	while ((ft_isdigit(**line) == 1) && **line != '\0' && k < 7)
	{
		flag = 1;
		a = a * 10 + (**line - 48) * mn;
		(*line)++;
		k++;
	}
	if (flag == 0)
		error(-2, "numerical value expected");
	return (a);
}
