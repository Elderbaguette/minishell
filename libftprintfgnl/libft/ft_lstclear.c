/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:53:10 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 11:56:13 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*l;

	if (!lst || !del)
	{
		return ;
	}
	while (*lst)
	{
		l = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = l;
	}
}
