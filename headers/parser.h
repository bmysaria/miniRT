#ifndef PARSER_H
# define PARSER_H

# include <unistd.h>

typedef struct s_check		t_check;
typedef struct s_rgb		t_rgb;
typedef struct s_list		t_list;
typedef struct s_vector		t_vector;
typedef struct s_camera		t_camera;
typedef struct s_camlist	t_camlist;
typedef struct s_ring		t_ring;
typedef struct s_screen		t_screen;
typedef struct s_scene		t_scene;
typedef struct s_light		t_light;
typedef struct s_object		t_object;
typedef struct s_figure		t_figure;
typedef struct s_intersect	t_intersect;
typedef struct s_ray		t_ray;
typedef struct s_data		t_data;
typedef struct s_basis		t_basis;

struct						s_vector
{
	double					x;
	double					y;
	double					z;
};

struct						s_basis
{
	t_vector				w;
	t_vector				u;
	t_vector				v;
};

struct						s_check
{
	int						r;
	int						a;
	int						c;
	int						l;
	int						sp;
	int						pl;
	int						sq;
	int						cy;
	int						tr;
};

struct						s_rgb
{
	int						r;
	int						g;
	int						b;
};

struct						s_list
{
	void					*content;
	struct s_list			*next;
};

struct						s_figure
{
	t_vector				c;
	t_vector				co;
	t_vector				cp;
	t_vector				p;
	double					d;
	double					r;
	double					h;
	t_rgb					color;
	t_vector				n;
	t_vector				p1;
	t_vector				p2;
	t_vector				p3;
	t_vector				p1_p2;
	t_vector				p1_p3;
	t_vector				p2_p3;
	t_vector				p2_p1;
};

struct						s_camera
{
	t_vector				o;
	t_vector				norm_vec;
	double					fov;
};

struct						s_camlist
{
	t_camera				*camera;
	struct s_camlist		*next;
	struct s_camlist		*prev;
};

struct						s_ring
{
	t_camlist				*current;
};

struct						s_screen
{
	t_vector				corner;
	t_vector				horisontal;
	t_vector				vertical;
	t_vector				p0;
	t_vector				p;
	t_vector				d;
	double					half_w;
	double					half_h;
	t_vector				u;
	t_vector				v;
	t_vector				w;
	int						height;
	int						width;
	t_camera				*current_cam;
};

struct						s_scene
{
	int						width;
	int						height;
	t_check					check;
	double					amb;
	t_rgb					amb_rgb;
	t_ring					*ring;
	t_list					*liglist;
	t_list					*figlist;
	t_data					*img;
	void					*mlx;
	void					*mlx_win;
};

struct						s_light
{
	t_vector				i;
	double					brightness;
	t_rgb					rgb;
};

struct						s_ray
{
	t_vector				o;
	t_vector				d;
};

struct						s_intersect
{
	double					range;
	t_ray					ray;
	double					t;
	t_vector				p;
	t_object				*object;
	t_vector				n;
	t_vector				color;
	int						new_color;
};

struct						s_object
{
	double					(*intersection)(t_figure *figure,
								t_intersect *inter);
	t_vector				(*normal_function)(t_figure *figure,
								t_intersect *inter);
	t_figure				figure;
};

struct						s_data
{
	void					*img;
	char					*addr;
	int						bits_per_pixel;
	int						line_length;
	int						endian;
};

int							error(int e, char const *message);
int							parser(char *line, t_scene *scene, int flag,
								int argc);
int							ft_isalpha(int c);
int							ft_strlen(char *s);
double						ft_atof(char **line);
int							ft_atoi(char **line);
int							ft_skip_to_digits(char **line);
int							ft_isdigit(int c);
int							resolution_filler(char *line, t_scene *scene);
int							cylinder_filler(char *line, t_scene *scene,
								t_object *object);
int							triangle_filler(char *line, t_scene *scene,
								t_object *object);
int							camera_filler(char *line, t_scene *scene);
int							check_scene(t_check *check);
int							ambient_filler(char *line, t_scene *scene);
int							light_filler(char *line, t_scene *scene);
int							sphere_filler(char *line, t_scene *scene,
								t_object *object);
int							plane_filler(char *line, t_scene *scene,
								t_object *object);
int							square_filler(char *line, t_scene *scene,
								t_object *object);
void						free_ring(t_ring *ring);
int							create_add_camlist(t_ring *ring, t_camera *camera);
int							norm_vec_check(t_vector vec);
void						ft_lstadd_back(t_list **lst, t_list *lst_new);
t_list						*ft_lstnew(void *content);
void						ft_lstclear(t_list **lst);
void						print_vector(t_vector *vec);
void						print_rgb(t_rgb *rgb);
t_vector					parse_vec(char **line);
t_vector					parse_norm_vec(char **line);
t_rgb						parse_rgb(char **line);
int							rgb_check(t_rgb *rgb);
int							scene_checker(t_check *check);
int							check_format(char **argv, int argc);
void						*ft_memset(void *b, int c, size_t len);
void						clear_struct(t_check *check);

#endif
