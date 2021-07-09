#include "../headers/minirt.h"

int			rgb_check(t_rgb *rgb)
{
	if (rgb->r < 0 || rgb->r > 255 || rgb->g < 0 || rgb->g > 255
			|| rgb->b < 0 || rgb->b > 255)
		error(-2, "improper color");
	return (0);
}

int			scene_checker(t_check *check)
{
	if (check->r > 1 || check->a > 1)
		error(-2, "resolution/ambient declared more than once");
	if (check->r == 0 || check->c == 0)
		error(-2, "lacks in resolution/camera");
	if (check->a == 0 && check->l == 0)
		error(-2, "no light");
	return (0);
}

int			check_format(char **argv, int argc)
{
	int		i;
	int		k;

	i = ft_strlen(argv[1]);
	if (i < 4)
		error(-1, "Improper scene format");
	if (argv[1][i - 1] != 't' || argv[1][i - 2] != 'r' || argv[1][i - 3] != '.')
		error(-1, "Improper scene format");
	if (argc == 3)
	{
		k = ft_strlen(argv[2]);
		if (k != 6)
			error(-1, "Improper screenshot argument");
		if (argv[2][0] != '-' || argv[2][1] != '-' || argv[2][2] != 's' ||
			argv[2][3] != 'a' || argv[2][4] != 'v' || argv[2][5] != 'e')
			error(-1, "Improper screenshot argument");
	}
	return (0);
}

void		clear_struct(t_check *check)
{
	check->r = 0;
	check->a = 0;
	check->c = 0;
	check->l = 0;
	check->sp = 0;
	check->pl = 0;
	check->sq = 0;
	check->cy = 0;
	check->tr = 0;
}
