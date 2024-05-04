/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:30 by aproust           #+#    #+#             */
/*   Updated: 2022/11/14 18:03:57 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	t_list *l1 = ft_lstnew("Aruberu");
// 	t_list *l2 = ft_lstnew("Puroust");
// 	t_list *l3 = ft_lstnew("Elderubaguette");
// 	l1->next = l2;
// 	l2->next = l3;
// 	printf("%d", ft_lstsize(l1));
// }
