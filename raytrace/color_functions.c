#include "../headers/minirt.h"

t_rgb		mul_color(t_rgb color, t_vector color2)
{
	t_rgb	res;

	res.r = (int)((double)color.r * color2.x);
	res.g = (int)((double)color.g * color2.y);
	res.b = (int)((double)color.b * color2.z);
	if (res.r > 255)
		res.r = 255;
	if (res.r < 0)
		res.r = 0;
	if (res.g > 255)
		res.g = 255;
	if (res.b < 0)
		res.b = 0;
	if (res.b > 255)
		res.b = 255;
	if (res.g < 0)
		res.g = 0;
	return (res);
}

int			create_rgb(t_rgb *color)
{
	int		t;

	t = 0;
	return (t << 24 | color->r << 16 | color->g << 8 | color->b);
}

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		color_create(t_intersect *inter)
{
	t_rgb	tmp;

	tmp = mul_color(inter->object->figure.color, inter->color);
	inter->new_color = create_rgb(&tmp);
}

void		ray_function(t_screen *screen, t_intersect *inter, int i, int j)
{
	dir_function(i, j, screen);
	inter->ray.d = screen->d;
	inter->ray.o = screen->current_cam->o;
}
