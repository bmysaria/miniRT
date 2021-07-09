#include "../headers/minirt.h"

t_vector		vec_sub(t_vector *a, t_vector *b)
{
	t_vector	vec;

	vec = vec_construct(a->x - b->x, a->y - b->y, a->z - b->z);
	return (vec);
}

double			vec_dist(t_vector *a, t_vector *b)
{
	t_vector	vec;

	vec = vec_sub(a, b);
	return (vec_abs(&vec));
}

t_vector		vec_mul(t_vector *a, double i)
{
	t_vector	vec;

	vec = vec_construct(a->x * i, a->y * i, a->z * i);
	return (vec);
}

t_vector		vec_sum(t_vector *a, t_vector *b)
{
	t_vector	vec;

	vec = vec_construct(a->x + b->x, a->y + b->y, a->z + b->z);
	return (vec);
}

t_vector		vec_div(t_vector *a, double i)
{
	t_vector	vec;

	vec = vec_construct(a->x / i, a->y / i, a->z / i);
	return (vec);
}
