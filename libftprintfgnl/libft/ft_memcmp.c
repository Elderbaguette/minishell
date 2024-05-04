/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:39 by aproust           #+#    #+#             */
/*   Updated: 2022/11/19 12:58:27 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str2 = (unsigned char *)s2;
	str1 = (unsigned char *)s1;
	i = 0;
	while (str1[i] == str2[i] && n > 1)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (str1[i] - str2[i]);
}

// int main()
// {
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	printf("Test : %d", ft_memcmp(s2, s3, 4));
// }
