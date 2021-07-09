#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include "get_next_line.h"
# include "parser.h"
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include "vector.h"

# define INF 1e9
# define SDVIG 1e-9

typedef struct	s_thread
{
	void		*scene;
	int			begin;
	int			stop;
}				t_thread;

void			light_iteration(t_scene *scene, t_intersect *inter);
int				light_intersection(t_scene *scene, t_intersect *linter);
int				general_intersection(t_scene *scene, t_intersect *inter);
void			dir_function(double i, double j, t_screen *screen);
void			screen_construct(t_screen *screen);
t_vector		ray_ray_2(double i, double j, t_screen *screen);
void			color_create(t_intersect *inter);
void			ray_function(t_screen *screen, t_intersect *inter,
					int i, int j);
int				free_scene(t_scene *scene);
t_vector		cylinder_normal(t_figure *cylinder, t_intersect *inter);
double			cyl_height(t_figure *cyl, t_intersect *inter,
					double t1, double t2);
double			cylinder_intersection(t_figure *cylinder, t_intersect *inter);
double			square_intersection(t_figure *square, t_intersect *inter);
t_vector		square_normal(t_figure *square, t_intersect *inter);
double			square_intersection(t_figure *square, t_intersect *inter);
double			triangle_intersection(t_figure *tr, t_intersect *inter);
t_vector		triangle_normal(t_figure *triangle, t_intersect *inter);
double			sphere_intersection(t_figure *sphere, t_intersect *inter);
t_vector		sphere_normal(t_figure *sphere, t_intersect *inter);
double			plane_intersection(t_figure *plane, t_intersect *inter);
t_vector		plane_normal(t_figure *plane, t_intersect *inter);
t_rgb			mul_color(t_rgb color, t_vector color2);
int				create_rgb(t_rgb *color);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			mlx_get_screen_size(int *width, int *height);
void			screenshot(t_scene *scene);

#endif
