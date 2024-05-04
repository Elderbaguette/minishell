/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:27 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 11:56:34 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*l1;

	l1 = (t_list *)malloc(sizeof(*l1));
	if (!l1)
		return (NULL);
	l1->content = content;
	l1->next = NULL;
	return (l1);
}
