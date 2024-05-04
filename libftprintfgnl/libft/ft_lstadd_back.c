/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:52:59 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 11:56:06 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lend;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lend = ft_lstlast(*lst);
	lend->next = new;
}

// void printlist(t_list *l)
// {
//     while(l)
//     {
//         printf("%s", (char *)l->content);
//         l = l->next;
//     }
// }

// int main()
// {
//     t_list *l1 = ft_lstnew("Aruberu");
//     t_list *l2 = ft_lstnew("Puroust");
// 	t_list *l3 = ft_lstnew("Elderubaguette");
//     void *p = &l1;
//     ft_lstadd_back(p, l2);
// 	ft_lstadd_back(p, l3);
//     printlist(l1);
//     return 0;
// }
