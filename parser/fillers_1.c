#include "../headers/minirt.h"

int				ambient_filler(char *line, t_scene *scene)
{
	line++;
	scene->amb = ft_atof(&line);
	if (scene->amb < 0 || scene->amb > 1)
		error(-2, "improper ambient lightning");
	scene->amb_rgb = parse_rgb(&line);
	scene->check.a += 1;
	return (0);
}

int				light_filler(char *line, t_scene *scene)
{
	t_light		*light;
	t_list		*elem;

	if (!(light = malloc(sizeof(t_light))))
		error(-1, "Allocation failure");
	elem = ft_lstnew((void*)light);
	line++;
	light->i = parse_vec(&line);
	light->brightness = ft_atof(&line);
	light->rgb = parse_rgb(&line);
	if (light->brightness <= 0 || light->brightness > 1)
		error(-1, "improper light");
	ft_lstadd_back(&scene->liglist, elem);
	scene->check.l += 1;
	return (0);
}

int				sphere_filler(char *line, t_scene *scene, t_object *object)
{
	t_list		*elem;

	line = line + 2;
	object->figure.c = parse_vec(&line);
	object->figure.d = ft_atof(&line);
	object->figure.r = object->figure.d / 2;
	object->figure.color = parse_rgb(&line);
	if (object->figure.d <= 0 || object->figure.r <= 0)
		error(-1, "improper sphere");
	object->intersection = &sphere_intersection;
	object->normal_function = &sphere_normal;
	elem = ft_lstnew(object);
	ft_lstadd_back(&scene->figlist, elem);
	scene->check.sp += 1;
	return (0);
}

int				plane_filler(char *line, t_scene *scene, t_object *object)
{
	t_list		*elem;

	line = line + 2;
	object->figure.c = parse_vec(&line);
	object->figure.n = parse_norm_vec(&line);
	object->figure.color = parse_rgb(&line);
	object->intersection = &plane_intersection;
	object->normal_function = &plane_normal;
	elem = ft_lstnew(object);
	ft_lstadd_back(&scene->figlist, elem);
	scene->check.pl += 1;
	return (0);
}

int				square_filler(char *line, t_scene *scene, t_object *object)
{
	t_list		*elem;

	line = line + 2;
	object->figure.c = parse_vec(&line);
	object->figure.n = parse_norm_vec(&line);
	object->figure.h = ft_atof(&line);
	object->figure.h = object->figure.h / 2;
	object->figure.color = parse_rgb(&line);
	if (object->figure.h <= 0)
		error(-2, "improper square");
	object->intersection = &square_intersection;
	object->normal_function = &square_normal;
	elem = ft_lstnew(object);
	ft_lstadd_back(&scene->figlist, elem);
	scene->check.sq += 1;
	return (0);
}
