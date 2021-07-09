#include "../headers/minirt.h"

int			gnl(t_scene *scene, char **argv, int argc)
{
	char	*line;
	int		fd;
	int		flag;

	flag = 1;
	clear_struct(&scene->check);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		parser(line, scene, flag, argc);
		free(line);
	}
	flag = 0;
	close(fd);
	parser(line, scene, flag, argc);
	free(line);
	exit(0);
}

int			main(int argc, char **argv)
{
	t_scene *scene;
	t_list	*figlist;
	t_list	*liglist;
	t_ring	*ring;

	if (argc == 2 || argc == 3)
	{
		check_format(argv, argc);
		if (!(scene = malloc(sizeof(t_scene))))
			error(-1, "Allocation failure");
		if (!(ring = malloc(sizeof(t_ring))))
			error(-1, "Allocation failure");
		figlist = NULL;
		liglist = NULL;
		ring->current = NULL;
		scene->ring = ring;
		scene->liglist = liglist;
		scene->figlist = figlist;
		gnl(scene, argv, argc);
	}
	if (argc < 2 || argc > 3)
		error(-1, "Wrong number of arguments");
	return (0);
}
