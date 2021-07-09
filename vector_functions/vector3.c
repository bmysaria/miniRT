#include "../headers/minirt.h"

t_vector		find_p(t_vector *o, double t, t_vector *d)
{
	t_vector	p;

	p = vec_construct(o->x + t * d->x, o->y + t * d->y, o->z + t * d->z);
	return (p);
}

int				vec_par(t_vector *a, t_vector *b)
{
	t_vector	vec;

	vec = vec_construct(a->y * b->z - a->z * b->y, a->z * b->x - a->x * b->z,
			a->x * b->y - a->y * b->x);
	if (fabs(dot(&vec, &vec)) <= 1E-9)
		return (1);
	return (0);
}

t_vector		cross_norma(t_vector *a, t_vector *b)
{
	t_vector	vec;

	vec = cross(a, b);
	return (vec_norma(&vec));
}

t_vector		sub_norma(t_vector *a, t_vector *b)
{
	t_vector	vec;

	vec = vec_sub(a, b);
	return (vec_norma(&vec));
}

t_vector		sub_div(t_vector *a, t_vector *b, double i)
{
	t_vector	vec;
	t_vector	res;

	vec = vec_sub(a, b);
	res = vec_div(&vec, i);
	return (res);
}
