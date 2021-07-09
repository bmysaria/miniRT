#include "../headers/minirt.h"

double			highlight(t_intersect *inter, t_vector *l)
{
	double		i;
	t_vector	v;
	t_vector	r;
	double		shine;
	double		d;

	shine = 50;
	r = vec_mul(&inter->n, 2);
	r = vec_mul(&r, dot(&inter->n, l));
	r = vec_sub(&r, l);
	v = vec_mul(&inter->ray.d, -1);
	d = dot(&r, &v);
	if (d < 0)
		return (0);
	i = pow(d, shine);
	return (i);
}

void			light_origin_dir(t_light *current_light, t_intersect *inter,
					t_intersect *linter)
{
	linter->range = vec_dist(&inter->p, &current_light->i);
	linter->ray.o = inter->p;
	linter->ray.d = sub_norma(&current_light->i, &inter->p);
	linter->object = inter->object;
	linter->n = inter->n;
	linter->p = inter->p;
}

double			coefficient(t_intersect *inter, t_intersect *linter)
{
	double		x;
	double		c;

	x = 0;
	c = 0;
	c = dot(&linter->n, &linter->ray.d);
	if (c > 0)
		x = highlight(inter, &linter->ray.d);
	if (c < 0)
		c = 0;
	c = c + x;
	return (c);
}

void			count_rgb(double c, double brightness, t_rgb *rgb,
					t_intersect *inter)
{
	t_vector	tmp_color;

	tmp_color = vec_construct(((double)(rgb->r)) / 255 * brightness * c,
		((double)(rgb->g)) / 255 * brightness * c,
		((double)(rgb->b)) / 255 * brightness * c);
	inter->color = vec_sum(&tmp_color, &inter->color);
}

void			light_iteration(t_scene *scene, t_intersect *inter)
{
	t_list		*ptr;
	double		c;
	t_intersect *linter;
	t_light		*current_light;

	if (!(linter = malloc(sizeof(t_intersect))))
		error(-1, "Allocation failure");
	inter->color = vec_construct(0, 0, 0);
	ptr = scene->liglist;
	while (ptr)
	{
		current_light = ptr->content;
		light_origin_dir(current_light, inter, linter);
		if (light_intersection(scene, linter) != -1)
		{
			c = coefficient(inter, linter);
			count_rgb(c, current_light->brightness, &current_light->rgb, inter);
		}
		ptr = ptr->next;
	}
	count_rgb(1, scene->amb, &scene->amb_rgb, inter);
	free(linter);
}
