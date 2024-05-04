/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:26 by aproust           #+#    #+#             */
/*   Updated: 2022/11/19 13:33:00 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	a;
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	a = ft_strlen(dest);
	i = 0;
	if (size <= a)
		return (size + ft_strlen(src));
	while (src[i] && a + 1 < size)
	{
	dest[a] = src[i];
	a++;
	i++;
	}
	dest[a] = '\0';
	return (ft_strlen(&src[i]) + ft_strlen(dest));
}
