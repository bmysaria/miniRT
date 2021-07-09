#include "../headers/minirt.h"
#include <unistd.h>

void		draw_screen(t_scene *scene, int h, int w, int fd)
{
	int var[3];

	var[0] = h - 1;
	while (var[0] >= 0)
	{
		var[1] = 0;
		while (var[1] < w)
		{
			var[2] = *(int*)(scene->img->addr +
					(var[0] * scene->img->line_length\
			+ var[1] * (scene->img->bits_per_pixel / 8)));
			write(fd, &var[2], 3);
			var[1]++;
		}
		var[0]--;
	}
}

void		filler(char arr_info[54], int w, int h, int size)
{
	arr_info[0] = 'B';
	arr_info[1] = 'M';
	arr_info[2] = size;
	arr_info[3] = size >> 8;
	arr_info[4] = size >> 16;
	arr_info[5] = size >> 24;
	arr_info[10] = 54;
	arr_info[14] = 40;
	arr_info[26] = 0;
	arr_info[28] = 24;
	arr_info[18] = w;
	arr_info[19] = w >> 8;
	arr_info[20] = w >> 16;
	arr_info[21] = w >> 24;
	arr_info[22] = h;
	arr_info[23] = h >> 8;
	arr_info[24] = h >> 16;
	arr_info[25] = h >> 24;
}

void		screenshot(t_scene *scene)
{
	int		fd;
	int		size;
	char	arr_info[54];

	fd = open("screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0666);
	while (scene->width % 4 != 0)
		scene->width--;
	size = 54 + (4 * scene->width * scene->height);
	ft_memset(arr_info, 0, 54);
	filler(arr_info, scene->width, scene->height, size);
	write(fd, arr_info, 54);
	draw_screen(scene, scene->height, scene->width, fd);
	close(fd);
	exit(0);
}
