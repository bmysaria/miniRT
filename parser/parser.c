#include "../headers/minirt.h"
#include "../headers/draw.h"
#include "../headers/draw_bonus.h"

int				free_scene(t_scene *scene)
{
	ft_lstclear(&(scene->figlist));
	ft_lstclear(&(scene->liglist));
	free_ring(scene->ring);
	free(scene);
	exit(0);
}

int				figure_filler(char *line, t_scene *scene, t_object *object)
{
	int			((*filler))(char *, t_scene *, t_object *);

	filler = NULL;
	if (*line == 's' && *(line + 1) == 'p')
		filler = &sphere_filler;
	else if (*line == 'p' && *(line + 1) == 'l')
		filler = &plane_filler;
	else if (*line == 'c' && *(line + 1) == 'y')
		filler = &cylinder_filler;
	else if ((*line == 't' && *(line + 1) == 'r'))
		filler = &triangle_filler;
	else if (*line == 's' && *(line + 1) == 'q')
		filler = &square_filler;
	filler(line, scene, object);
	return (0);
}

int				check(t_scene *scene, int argc)
{
	scene_checker(&scene->check);
	draw(scene, argc);
	free_scene(scene);
	return (0);
}

int				parser(char *line, t_scene *scene, int flag, int argc)
{
	t_object	*object;

	if (*line == 'A')
		ambient_filler(line, scene);
	else if (*line == 'R')
		resolution_filler(line, scene);
	else if ((*line == 's' && *(line + 1) == 'p') ||
			(*line == 'p' && *(line + 1) == 'l')
			|| (*line == 'c' && *(line + 1) == 'y') ||
			(*line == 't' && *(line + 1) == 'r')
			|| (*line == 's' && *(line + 1) == 'q'))
	{
		if (!(object = malloc(sizeof(t_object))))
			error(-1, "Allocation failure");
		figure_filler(line, scene, object);
	}
	else if (*line == 'l')
		light_filler(line, scene);
	else if (*line == 'c')
		camera_filler(line, scene);
	if (flag == 0)
		check(scene, argc);
	return (0);
}
