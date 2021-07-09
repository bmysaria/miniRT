#include "../headers/minirt.h"

void			inter_init(t_intersect *inter, double res, t_object *object)
{
	inter->t = res;
	inter->object = object;
	inter->p = find_p(&inter->ray.o, inter->t - SDVIG, &inter->ray.d);
	inter->n = inter->object->normal_function(&(inter->object->figure), inter);
	if (dot(&inter->n, &inter->ray.d) > 0)
		inter->n = vec_mul(&inter->n, -1);
}

int				general_intersection(t_scene *scene, t_intersect *inter)
{
	double		res[2];
	t_list		*ptr;
	t_object	*object;

	ptr = scene->figlist;
	res[0] = INF;
	while (ptr)
	{
		res[1] = (*(((t_object *)(ptr->content))->intersection))(&((t_object *)
					(ptr->content))->figure, inter);
		if (res[1] != -1 && res[1] < res[0])
		{
			res[0] = res[1];
			object = (t_object *)(ptr->content);
		}
		ptr = ptr->next;
	}
	if (res[0] != INF)
	{
		inter_init(inter, res[0], object);
		return (0);
	}
	return (-1);
}
