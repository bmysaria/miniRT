#include "../headers/minirt.h"

t_vector		triangle_normal(t_figure *triangle, t_intersect *inter)
{
	t_vector	n;
	t_vector	p2_p1;
	t_vector	p3_p1;

	(void)(inter);
	p2_p1 = vec_sub(&triangle->p2, &triangle->p1);
	p3_p1 = vec_sub(&triangle->p3, &triangle->p1);
	n = cross(&p2_p1, &p3_p1);
	n = vec_norma(&n);
	return (n);
}

double			triangle_intersection(t_figure *tr, t_intersect *inter)
{
	double		t;
	t_vector	temp_p1_p;
	t_vector	temp_p2_p;
	t_vector	p;

	tr->n = triangle_normal(tr, inter);
	tr->c = tr->p1;
	t = plane_intersection(tr, inter);
	if (t != (-1))
	{
		p = find_p(&inter->ray.o, t, &inter->ray.d);
		temp_p1_p = vec_sub(&p, &tr->p1);
		temp_p1_p = vec_norma(&temp_p1_p);
		temp_p2_p = vec_sub(&p, &tr->p2);
		temp_p2_p = vec_norma(&temp_p2_p);
		if (dot(&temp_p1_p, &tr->p1_p2) > dot(&tr->p1_p3, &tr->p1_p2)
				&& dot(&temp_p1_p, &tr->p1_p3) > dot(&tr->p1_p3, &tr->p1_p2)
				&& dot(&temp_p2_p, &tr->p2_p1) > dot(&tr->p2_p1, &tr->p2_p3)
				&& dot(&temp_p2_p, &tr->p2_p3) > dot(&tr->p2_p1, &tr->p2_p3))
			return (t);
	}
	return (-1);
}
