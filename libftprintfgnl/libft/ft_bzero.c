/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:31:01 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 11:55:44 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t count)
{
	unsigned char	*str;
	size_t			i;

	str = ptr;
	i = 0;
	while (i < count)
	{
		str[i] = '\0';
		i++;
	}
}
