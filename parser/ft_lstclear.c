#include "../headers/minirt.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*start;

	start = *lst;
	if (!(*lst))
		return ;
	while (start)
	{
		ptr = start->next;
		free(start->content);
		free(start);
		start = ptr;
	}
	*lst = NULL;
}
