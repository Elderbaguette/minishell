/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:00:01 by aproust           #+#    #+#             */
/*   Updated: 2023/10/09 13:43:03 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				res;

	i = 0;
	while (s1[i] && s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	res = ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (res);
}
