#include "../headers/minirt.h"

int				resolution_filler(char *line, t_scene *scene)
{
	int			real_width;
	int			real_height;

	real_width = 0;
	real_height = 0;
	mlx_get_screen_size(&real_width, &real_height);
	line++;
	scene->width = ft_atoi(&line);
	scene->height = ft_atoi(&line);
	if (scene->width < 1 || scene->height < 1)
		error(-2, "improper resolution");
	if (scene->width > real_width)
		scene->width = real_width;
	if (scene->height > real_height)
		scene->height = real_height;
	scene->check.r += 1;
	return (0);
}

int				cylinder_filler(char *line, t_scene *scene, t_object *object)
{
	t_list		*elem;

	line = line + 2;
	object->figure.c = parse_vec(&line);
	object->figure.n = parse_norm_vec(&line);
	object->figure.d = ft_atof(&line);
	object->figure.r = object->figure.d / 2;
	object->figure.h = ft_atof(&line);
	object->figure.h = object->figure.h / 2;
	object->figure.color = parse_rgb(&line);
	if (object->figure.h <= 0 || object->figure.d <= 0)
		error(-2, "improper cylinder");
	object->intersection = &cylinder_intersection;
	object->normal_function = &cylinder_normal;
	elem = ft_lstnew(object);
	ft_lstadd_back(&scene->figlist, elem);
	scene->check.cy += 1;
	return (0);
}

int				triangle_filler(char *line, t_scene *scene, t_object *object)
{
	t_list		*elem;

	line = line + 2;
	object->figure.p1 = parse_vec(&line);
	object->figure.p2 = parse_vec(&line);
	object->figure.p3 = parse_vec(&line);
	object->figure.color = parse_rgb(&line);
	object->figure.p1_p2 = vec_sub(&object->figure.p2, &object->figure.p1);
	object->figure.p1_p2 = vec_norma(&object->figure.p1_p2);
	object->figure.p1_p3 = vec_sub(&object->figure.p3, &object->figure.p1);
	object->figure.p1_p3 = vec_norma(&object->figure.p1_p3);
	object->figure.p2_p3 = vec_sub(&object->figure.p3, &object->figure.p2);
	object->figure.p2_p3 = vec_norma(&object->figure.p2_p3);
	object->figure.p2_p1 = vec_sub(&object->figure.p1, &object->figure.p2);
	object->figure.p2_p1 = vec_norma(&object->figure.p2_p1);
	if (vec_par(&object->figure.p2, &object->figure.p1) == 1 ||
			vec_par(&object->figure.p2, &object->figure.p3) == 1 ||
			vec_par(&object->figure.p3, &object->figure.p1) == 1)
		error(-2, "improper triangle");
	object->intersection = &triangle_intersection;
	object->normal_function = &triangle_normal;
	elem = ft_lstnew(object);
	ft_lstadd_back(&scene->figlist, elem);
	scene->check.tr += 1;
	return (0);
}

int				camera_filler(char *line, t_scene *scene)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(t_camera))))
		error(-1, "Allocation failure");
	line++;
	camera->o = parse_vec(&line);
	camera->norm_vec = parse_norm_vec(&line);
	camera->fov = ft_atof(&line);
	camera->fov = camera->fov * M_PI / 180;
	if (camera->fov <= 0 || camera->fov > 180)
		error(-2, "improper camera");
	create_add_camlist(scene->ring, camera);
	scene->check.c += 1;
	return (0);
}
