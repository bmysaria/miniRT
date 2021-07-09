#include "../headers/minirt.h"

t_vector		sum_mul(t_vector *a, t_vector *b, double i)
{
	t_vector	vec;

	vec = vec_mul(b, i);
	vec = vec_sum(a, &vec);
	return (vec);
}

t_vector		sub_mul(t_vector *a, t_vector *b, double i)
{
	t_vector	vec;

	vec = vec_mul(b, i);
	vec = vec_sub(a, &vec);
	return (vec);
}
