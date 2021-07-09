#include "../headers/minirt.h"

t_vector	sphere_normal(t_figure *sphere, t_intersect *inter)
{
	t_vector	n;
	t_vector	c;
	t_vector	p;

	p = inter->p;
	c = sphere->c;
	n = sub_norma(&p, &c);
	return (n);
}

double		quad_equation(double a, double b, double c)
{
	double	dis;
	double	t1;
	double	t2;

	dis = b * b - 4 * a * c;
	if (dis < 0)
		return (-1);
	t1 = (-b + sqrt(dis)) / (2 * a);
	t2 = (-b - sqrt(dis)) / (2 * a);
	if ((t1 > 0) && (t2 > 0))
		return ((t1 > t2) ? t2 : t1);
	else if (t1 > 0)
		return (t1);
	else if (t2 > 0)
		return (t2);
	else
		return (-1);
}

double		sphere_intersection(t_figure *sphere, t_intersect *inter)
{
	t_vector	oc;
	double		a;
	double		b;
	double		c;

	oc = vec_sub(&inter->ray.o, &sphere->c);
	a = dot(&inter->ray.d, &inter->ray.d);
	b = 2 * dot(&oc, &inter->ray.d);
	c = dot(&oc, &oc) - sphere->r * sphere->r;
	return (quad_equation(a, b, c));
}
