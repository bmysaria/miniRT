#include "../headers/minirt.h"

t_vector		vec_construct(double x, double y, double z)
{
	t_vector	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double			dot(t_vector *a, t_vector *b)
{
	double		res;

	res = (a->x * b->x + a->y * b->y + a->z * b->z);
	return (res);
}

t_vector		cross(t_vector *a, t_vector *b)
{
	t_vector	vec;

	vec = vec_construct(a->y * b->z - a->z * b->y,
			a->z * b->x - a->x * b->z, a->x * b->y - a->y * b->x);
	return (vec);
}

t_vector		vec_norma(t_vector *a)
{
	t_vector	b;

	b.x = a->x / sqrt(dot(a, a));
	b.y = a->y / sqrt(dot(a, a));
	b.z = a->z / sqrt(dot(a, a));
	return (b);
}

double			vec_abs(t_vector *a)
{
	double		ans;

	ans = sqrt(a->x * a->x + a->y * a->y + a->z * a->z);
	return (ans);
}
