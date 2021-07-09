#include "../headers/minirt.h"

int	error(int e, char const *message)
{
	printf("Error\n");
	if (e == -1)
		printf("%s\n", message);
	else if (e == -2)
		printf("Invalid scene: %s\n", message);
	else if (e == -3)
		printf("Found invalid symbol instead of a digit\n");
	exit(-1);
}
