/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:36:45 by aproust           #+#    #+#             */
/*   Updated: 2022/11/21 11:38:27 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*memory;

	if ((elementCount >= SIZE_MAX || elementSize >= SIZE_MAX))
		return (NULL);
	memory = malloc(elementSize * elementCount);
	if (!memory)
		return (NULL);
	ft_bzero (memory, (elementCount * elementSize));
	return (memory);
}

// int	main (void)
// {
// 	void *str = ft_calloc(0, 0);
// 	void *str1 =
// 	if (str == ((void*)0))
// 		printf("Truc");
// }
