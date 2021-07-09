#include "../headers/minirt.h"

t_vector		square_normal(t_figure *square, t_intersect *inter)
{
	(void)(inter);
	return (vec_norma(&square->n));
}

t_basis			new_basis(t_vector vec)
{
	t_basis		basis;
	t_vector	r1;
	t_vector	r2;

	r1 = vec_construct(0, 1, 0);
	r2 = vec_construct(1, 0, 0);
	basis.w = vec;
	if (vec_par(&basis.w, &r1) != 1)
		basis.u = cross_norma(&r1, &basis.w);
	else
		basis.u = cross_norma(&r2, &basis.w);
	basis.v = cross(&basis.w, &basis.u);
	return (basis);
}

double			square_intersection(t_figure *square, t_intersect *inter)
{
	double		t;
	double		dott[2];
	t_basis		basis;
	t_vector	cp;
	t_vector	p;

	t = plane_intersection(square, inter);
	if (t != (-1))
	{
		p = find_p(&inter->ray.o, t, &inter->ray.d);
		cp = vec_sub(&p, &square->c);
		basis = new_basis(square->n);
		dott[0] = dot(&cp, &basis.u);
		dott[1] = dot(&cp, &basis.v);
		if (fabs(dott[0]) <= square->h && fabs(dott[1]) <= square->h)
			return (t);
	}
	return (-1);
}
