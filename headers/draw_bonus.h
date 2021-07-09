#ifndef DRAW_BONUS_H
# define DRAW_BONUS_H

# include "minirt.h"
# define RT_THREAD 100
# include <pthread.h>

void			pre_iteration(t_scene *scene);
int				draw(t_scene *scene, int argc);
void			*pro_iteration(void *arg);
int				change_cam_bonus(int key, t_scene *scene);
void			pixel_iteration_bonus(t_scene *scene, int begin, int stop);

#endif
