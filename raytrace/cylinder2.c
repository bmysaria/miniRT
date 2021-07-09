#include "../headers/minirt.h"

t_vector		cylinder_normal(t_figure *cylinder, t_intersect *inter)
{
	t_vector	n;
	t_vector	v;
	double		ppr;
	t_vector	c1;
	t_vector	c0;

	v = vec_sub(&inter->p, &cylinder->c);
	ppr = dot(&v, &cylinder->n);
	c1 = vec_mul(&cylinder->n, ppr);
	c0 = vec_sum(&cylinder->c, &c1);
	n = sub_div(&inter->p, &c0, cylinder->d / 2);
	return (n);
}

double			cyl_height(t_figure *cy, t_intersect *in, double t1, double t2)
{
	double		x[2];
	t_vector	cp1;
	t_vector	cp2;
	t_vector	p[2];

	p[0] = find_p(&in->ray.o, t1, &in->ray.d);
	p[1] = find_p(&in->ray.o, t2, &in->ray.d);
	cp1 = vec_sub(&p[0], &cy->c);
	cp2 = vec_sub(&p[1], &cy->c);
	x[0] = dot(&cy->n, &cp1);
	x[1] = dot(&cy->n, &cp2);
	if ((t1 > 0) && (t2 > 0))
	{
		if (-cy->h <= x[0] && x[0] <= cy->h && -cy->h <= x[1] && x[1] <= cy->h)
			return ((t1 > t2) ? t2 : t1);
		else if (-cy->h <= x[0] && x[0] <= cy->h)
			return (t1);
		else if (-cy->h <= x[1] && x[1] <= cy->h)
			return (t2);
	}
	else if (-cy->h <= x[0] && x[0] <= cy->h && t1 > 0)
		return (t1);
	else if (-cy->h <= x[1] && x[1] <= cy->h && t2 > 0)
		return (t2);
	return (-1);
}
