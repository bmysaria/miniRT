#include "../headers/minirt.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*elem;

	if (!(elem = (t_list*)malloc(sizeof(t_list))))
		return (0);
	else
	{
		elem->content = content;
		elem->next = 0;
		return (elem);
	}
}
