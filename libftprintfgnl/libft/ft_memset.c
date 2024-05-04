/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:49 by aproust           #+#    #+#             */
/*   Updated: 2022/11/15 10:30:15 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t counter)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = pointer;
	while (i < counter)
	{
		str[i] = value;
		i++;
	}
	return (pointer);
}

// int main(void)
// {
//     char str[] = "Bpnknk";

//     printf("%s\n", str);
//     ft_memset(str, 'L', 4);
//     printf("%s", str);
// }
