/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:19 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 11:56:28 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void printlist(t_list *l)
// {
//     while(l)
//     {
//         printf("%s", (char *)l->content);
//         l = l->next;
//     }
// }

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int main(void)
// {
// 	t_list *l1 = ft_lstnew("Aruberu");
// 	t_list *l2 = ft_lstnew("Puroust");
// 	t_list *l3 = ft_lstnew("Elderubaguette");
// 	l1->next = l2;
// 	l2->next = l3;
// 	ft_lstlast(l1);
// }
