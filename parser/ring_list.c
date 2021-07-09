#include "../headers/minirt.h"

void			free_ring(t_ring *ring)
{
	t_camlist	*tmp;
	t_camlist	*tmp2;

	if (ring->current)
	{
		tmp = ring->current;
		tmp2 = ring->current;
		while (tmp->next != tmp2 && tmp->next != NULL)
		{
			free(tmp->camera);
			tmp = tmp->next;
		}
		ring->current = NULL;
	}
	free(ring);
}

void			new_current(t_camlist *camlist, t_ring *ring)
{
	t_camlist	*tmp;
	t_camlist	*tmp2;
	int			i;

	i = 1;
	tmp = ring->current;
	tmp2 = ring->current;
	while (tmp->next != tmp2 && tmp->next != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	ring->current->prev = camlist;
	camlist->next = ring->current;
	tmp->next = camlist;
	camlist->prev = tmp;
}

int				create_add_camlist(t_ring *ring, t_camera *camera)
{
	t_camlist	*camlist;

	if (!(camlist = malloc(sizeof(t_camlist))))
		return (-1);
	camlist->camera = camera;
	camlist->next = camlist;
	camlist->prev = camlist;
	if (ring->current)
		new_current(camlist, ring);
	else
		ring->current = camlist;
	return (0);
}
