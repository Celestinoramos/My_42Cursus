/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cramos-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 09:51:21 by cramos-c          #+#    #+#             */
/*   Updated: 2024/05/20 09:51:25 by cramos-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*new;
	t_list	*map;

	if (lst == NULL)
		return (NULL);
	map = NULL;
	temp = lst;
	while (temp != NULL)
	{
		new = ft_lstnew(f(temp->content));
		if (new != NULL)
			ft_lstadd_back(&map, new);
		else
			ft_lstclear(&new, del);
		temp = temp->next;
	}
	return (map);
}
