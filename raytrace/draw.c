#include "../headers/draw.h"

int				change_cam(int key, t_scene *scene)
{
	if (key == 53)
		free_scene(scene);
	if (key == 123 || key == 124)
	{
		if (key == 124)
			scene->ring->current = scene->ring->current->next;
		if (key == 123)
			scene->ring->current = scene->ring->current->prev;
		pixel_iteration(scene);
		mlx_put_image_to_window(scene->mlx, scene->mlx_win,
				scene->img->img, 0, 0);
	}
	return (0);
}

void			iteration(t_scene *scene, t_intersect *inter, t_screen *screen)
{
	int			i;
	int			j;

	j = 0;
	while (j < scene->height)
	{
		i = 0;
		while (i < screen->width)
		{
			ray_function(screen, inter, i, j);
			if (general_intersection(scene, inter) == 0)
			{
				light_iteration(scene, inter);
				color_create(inter);
				my_mlx_pixel_put(scene->img, i, j, inter->new_color);
			}
			else
				my_mlx_pixel_put(scene->img, i, j, 0);
			i++;
		}
		j++;
	}
}

void			pixel_iteration(t_scene *scene)
{
	t_intersect *inter;
	t_screen	*screen;

	if (!(inter = malloc(sizeof(t_intersect))))
		error(-1, "Allocation error");
	if (!(screen = malloc(sizeof(t_screen))))
		error(-1, "Allocation error");
	screen->current_cam = scene->ring->current->camera;
	screen->width = scene->width;
	screen->height = scene->height;
	inter->new_color = 0;
	screen_construct(screen);
	iteration(scene, inter, screen);
	free(inter);
	free(screen);
}

int				draw(t_scene *scene, int argc)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, scene->width, scene->height,
		"miniRT");
	img.img = mlx_new_image(mlx, scene->width, scene->height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	scene->img = &img;
	scene->mlx = mlx;
	scene->mlx_win = mlx_win;
	pixel_iteration(scene);
	if (argc == 3)
	{
		screenshot(scene);
		return (0);
	}
	mlx_hook(mlx_win, 2, 0, &change_cam, scene);
	mlx_hook(mlx_win, 17, 0, &free_scene, scene);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
