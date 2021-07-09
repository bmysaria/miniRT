#ifndef VECTOR_H
# define VECTOR_H
# include <math.h>

t_vector	vec_construct(double x, double y, double z);
double		dot(t_vector *a, t_vector *b);
t_vector	cross(t_vector *a, t_vector *b);
t_vector	vec_norma(t_vector *vec);
double		vec_abs(t_vector *vec);
double		vec_dist(t_vector *a, t_vector *b);
t_vector	vec_sub(t_vector *a, t_vector *b);
t_vector	vec_mul(t_vector *a, double i);
t_vector	vec_sum(t_vector *a, t_vector *b);
t_vector	vec_div(t_vector *a, double i);
t_vector	find_p(t_vector *o, double t, t_vector *d);
int			vec_par(t_vector *a, t_vector *b);
t_vector	sum_mul(t_vector *a, t_vector *b, double i);
t_vector	sub_mul(t_vector *a, t_vector *b, double i);
t_vector	sub_norma(t_vector *a, t_vector *b);
t_vector	sub_div(t_vector *a, t_vector *b, double i);
t_vector	cross_norma(t_vector *a, t_vector *b);
t_vector	sum_mul(t_vector *a, t_vector *b, double i);
t_vector	sub_mul(t_vector *a, t_vector *b, double i);

#endif
