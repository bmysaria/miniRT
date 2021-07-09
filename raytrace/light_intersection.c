#include "../headers/minirt.h"

int				shadow_check(double res1, t_intersect *linter)
{
	t_vector	p1;
	double		range1;

	p1 = find_p(&linter->ray.o, res1, &linter->ray.d);
	range1 = vec_dist(&p1, &linter->p);
	if (range1 < linter->range)
	{
		return (-1);
	}
	return (0);
}

int				light_intersection(t_scene *scene, t_intersect *linter)
{
	t_list		*ptr;
	t_object	*object;
	double		res1;
	double		res2;

	res1 = INF;
	ptr = scene->figlist;
	while (ptr)
	{
		res2 = (*(((t_object *)(ptr->content))->intersection))
			(&((t_object *)(ptr->content))->figure, linter);
		if (res2 != -1)
		{
			if (res2 < res1)
			{
				res1 = res2;
				object = (t_object *)(ptr->content);
			}
		}
		ptr = ptr->next;
	}
	if (res1 != INF)
		return (shadow_check(res1, linter));
	return (0);
}
