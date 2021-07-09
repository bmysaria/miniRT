#include "../headers/draw_bonus.h"

int				change_cam_bonus(int key, t_scene *scene)
{
	t_camera	*current_cum;

	current_cum = scene->ring->current->camera;
	if (key == 53)
		free_scene(scene);
	if (key == 123 || key == 124 || key == 125 || key == 126)
	{
		if (key == 124)
			scene->ring->current = scene->ring->current->next;
		if (key == 123)
			scene->ring->current = scene->ring->current->prev;
		if (key == 126)
			scene->ring->current->camera->o =
				sum_mul(&current_cum->o, &current_cum->norm_vec, 20);
		if (key == 125)
			scene->ring->current->camera->o =
				sub_mul(&current_cum->o, &current_cum->norm_vec, 20);
		pre_iteration(scene);
		mlx_put_image_to_window(scene->mlx, scene->mlx_win,
				scene->img->img, 0, 0);
	}
	return (0);
}

void			pre_iteration(t_scene *scene)
{
	pthread_t	t_rt[RT_THREAD];
	t_thread	thread[RT_THREAD];
	int			k;
	int			beg_stop[2];
	int			step;

	k = -1;
	step = scene->width / RT_THREAD;
	beg_stop[0] = 0;
	while (++k < RT_THREAD)
	{
		beg_stop[1] = scene->width;
		if (k < (RT_THREAD - 1))
			beg_stop[1] = beg_stop[0] + step;
		thread[k].scene = scene;
		thread[k].begin = beg_stop[0];
		thread[k].stop = beg_stop[1];
		if ((pthread_create(&t_rt[k], NULL, &pro_iteration, &thread[k])) != 0)
			error(-1, "Pthread create failure");
		beg_stop[0] = beg_stop[1];
	}
	k = -1;
	while (++k < RT_THREAD)
		if ((pthread_join(t_rt[k], NULL)) != 0)
			error(-1, "Pthread join failure");
}

void			*pro_iteration(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)(arg);
	pixel_iteration_bonus(thread->scene, thread->begin, thread->stop);
	return (NULL);
}
