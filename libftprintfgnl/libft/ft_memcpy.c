/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:42 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 11:54:22 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*destination;
	const char	*source;

	if (!src && !dest)
		return (NULL);
	destination = (char *) dest;
	source = (char *) src;
	i = 0;
	if (n == 0)
		return (dest);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}

// int main()
//  {
//         char str[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";

//         char str1[] = "";
//         printf("%p\n", ft_memcpy(str, str1, 2));
//         printf("%s\n", &str[2]);
//         printf("%s", str1);
//  }
