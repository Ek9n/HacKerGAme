/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:24:45 by sung-hle          #+#    #+#             */
/*   Updated: 2023/07/25 19:33:57 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*next;
	t_list	*head;

	if (!f || !lst)
		return (0);
	head = NULL;
	while (lst)
	{
		next = ft_lstnew((*f)(lst->content));
		if (!next)
		{
			ft_lstclear(&head, del);
			return (0);
		}
		else
		{
			ft_lstadd_back(&head, next);
			lst = lst->next;
		}
	}
	return (head);
}
