#include "../headers/minirt.h"

t_vector		plane_normal(t_figure *plane, t_intersect *inter)
{
	(void)(inter);
	return (plane->n);
}

double			plane_intersection(t_figure *plane, t_intersect *inter)
{
	double		a;
	double		denom;
	double		t;
	t_vector	co;

	denom = dot(&plane->n, &inter->ray.d);
	co = vec_sub(&plane->c, &inter->ray.o);
	a = dot(&co, &plane->n);
	t = a / denom;
	if (t >= 0)
		return (t);
	return (-1);
}
