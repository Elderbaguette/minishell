/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:24 by aproust           #+#    #+#             */
/*   Updated: 2022/11/18 17:58:58 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*liste;
	t_list	*lisdos;

	if (!del || !f || !lst)
		return (NULL);
	lisdos = NULL;
	while (lst)
	{
		liste = ft_lstnew((*f)(lst->content));
		if (!liste)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&lisdos, liste);
		lst = lst->next;
	}
	return (lisdos);
}
