/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:35 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 13:34:09 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	if (c == '\0')
		return (&str[ft_strlen(s)]);
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
		{
			return (&str[i]);
		}
		i++;
	}
	return (NULL);
}

// int	main()
// {
// 	char *str;
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	// printf("s : %d\n", s[0]);
// 	str = ft_memchr(s, 2, 3);
// 	printf("s fin : %d\n", str[0]);
// }
