/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:43 by aproust           #+#    #+#             */
/*   Updated: 2022/11/21 12:23:07 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str && n == 0)
		return (0);
	if (to_find[j] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		if (to_find[j] == str[i])
		{
			while (to_find[j] && str[i + j] == to_find[j] && i + j < n)
				j++;
			if (to_find[j] == '\0')
				return ((char *)&str[i]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
