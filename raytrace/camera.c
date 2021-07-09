#include "../headers/minirt.h"

void	screen_basis(t_screen *screen)
{
	t_vector r1;
	t_vector r2;

	r1 = vec_construct(0, 1, 0);
	r2 = vec_construct(1, 0, 0);
	screen->w = vec_norma(&screen->current_cam->norm_vec);
	screen->w = vec_mul(&screen->w, -1);
	if (vec_par(&screen->w, &r1) != 1)
	{
		screen->u = cross_norma(&r1, &screen->w);
		screen->v = cross_norma(&screen->w, &screen->u);
	}
	else
	{
		screen->u = cross_norma(&r2, &screen->w);
		screen->v = cross_norma(&screen->w, &screen->u);
	}
}

void	half_w_half_h_function(t_screen *screen)
{
	double iar;

	iar = (double)screen->height / (double)screen->width;
	screen->half_w = tan(screen->current_cam->fov / 2);
	screen->half_h = iar * screen->half_w;
}

void	corner_function(t_screen *screen)
{
	screen->corner = screen->current_cam->o;
	screen->corner = sum_mul(&screen->corner, &screen->v, screen->half_h);
	screen->corner = sub_mul(&screen->corner, &screen->u, screen->half_w);
	screen->corner = vec_sub(&screen->corner, &screen->w);
	screen->horisontal = vec_mul(&screen->u, (2 * screen->half_w));
	screen->vertical = vec_mul(&screen->v, (2 * screen->half_h));
}

void	screen_construct(t_screen *screen)
{
	screen_basis(screen);
	half_w_half_h_function(screen);
	corner_function(screen);
}

void	dir_function(double i, double j, t_screen *screen)
{
	double u;
	double v;

	u = (i) / screen->width;
	v = (j) / screen->height;
	screen->p = screen->corner;
	screen->p = sum_mul(&screen->p, &screen->horisontal, u);
	screen->p = sub_mul(&screen->p, &screen->vertical, v);
	screen->d = sub_norma(&screen->p, &screen->current_cam->o);
}
