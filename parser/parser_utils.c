#include "../headers/minirt.h"

t_vector		parse_vec(char **line)
{
	t_vector	vec;

	vec.x = ft_atof(line);
	vec.y = ft_atof(line);
	vec.z = ft_atof(line);
	return (vec);
}

t_vector		parse_norm_vec(char **line)
{
	t_vector	vec;

	vec.x = ft_atof(line);
	vec.y = ft_atof(line);
	vec.z = ft_atof(line);
	if (vec.x == 0 && vec.y == 0 && vec.z == 0)
		error(-2, "improper normalized orientation vector");
	vec = vec_norma(&vec);
	return (vec);
}

t_rgb			parse_rgb(char **line)
{
	t_rgb		rgb;

	rgb.r = ft_atoi(line);
	rgb.g = ft_atoi(line);
	rgb.b = ft_atoi(line);
	rgb_check(&rgb);
	return (rgb);
}
