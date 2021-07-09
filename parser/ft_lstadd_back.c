/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmysaria <bmysaria@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 13:20:21 by bmysaria          #+#    #+#             */
/*   Updated: 2021/04/04 18:45:07 by bmysaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/minirt.h"

void	ft_lstadd_back(t_list **lst, t_list *lst_new)
{
	t_list	*ptr;

	ptr = *lst;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = lst_new;
	}
	else
		*lst = lst_new;
}
