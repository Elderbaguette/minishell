/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:54:45 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 13:36:03 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t size)
{
	unsigned char	*strdest;
	unsigned char	*strsrc;

	strdest = (unsigned char *)destination;
	strsrc = (unsigned char *)source;
	if (!destination && !source)
		return (NULL);
	if (destination > source)
	{
		while (size-- > 0)
		{
			strdest[size] = strsrc[size];
		}
		return (destination);
	}
	else
		ft_memcpy(destination, source, size);
	destination = strdest;
	return (destination);
}
