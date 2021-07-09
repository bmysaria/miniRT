#include "../headers/minirt.h"

double		ft_atof_2(char **line, double mn)
{
	double	b;
	double	a;
	int		k;

	k = 1;
	(*line)++;
	b = 0.1;
	a = 0;
	while (ft_isdigit(**line) && **line != '\0' && k < 7)
	{
		a = a + (b * (**line - 48) * mn);
		b = b * 0.1;
		(*line)++;
		k++;
	}
	return (a);
}

double		ft_atof(char **line)
{
	double	a;
	double	mn;
	int		flag;

	a = 0;
	mn = 1.0;
	flag = 0;
	ft_skip_to_digits(line);
	if (**line == '-')
		mn = -1.0;
	if ((**line == '-' || **line == '+') && **line != '\0')
		(*line)++;
	while (ft_isdigit(**line) && **line != '\0' && flag < 19)
	{
		flag = 1;
		a = a * 10 + (**line - 48) * mn;
		(*line)++;
		flag++;
	}
	if (**line == '.')
		a = a + ft_atof_2(line, mn);
	if (flag == 0)
		error(-2, "numerical value expected");
	return (a);
}
