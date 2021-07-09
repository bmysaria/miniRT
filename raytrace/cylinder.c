#include "../headers/minirt.h"

double			cyl_a(t_vector *d, t_vector *n)
{
	return (dot(d, d)) - dot(n, d) * dot(n, d);
}

double			cyl_b(t_vector *co, t_vector *d, t_vector *n)
{
	return (2 * (dot(co, d) - dot(co, n) * dot(n, d)));
}

double			cyl_c(t_vector *co, t_vector *n, double r)
{
	return ((dot(co, co) - dot(n, co) * dot(n, co) - r * r));
}

double			cylinder_intersection(t_figure *cylinder, t_intersect *inter)
{
	t_vector	abc;
	double		dis;
	double		t1;
	double		t2;
	t_vector	co;

	co = vec_sub(&inter->ray.o, &cylinder->c);
	abc.x = cyl_a(&inter->ray.d, &cylinder->n);
	abc.y = cyl_b(&co, &inter->ray.d, &cylinder->n);
	abc.z = cyl_c(&co, &cylinder->n, cylinder->r);
	dis = abc.y * abc.y - 4 * abc.x * abc.z;
	if (dis < 0)
		return (-1);
	t1 = (-abc.y + sqrt(dis)) / (2 * abc.x);
	t2 = (-abc.y - sqrt(dis)) / (2 * abc.x);
	return (cyl_height(cylinder, inter, t1, t2));
}
