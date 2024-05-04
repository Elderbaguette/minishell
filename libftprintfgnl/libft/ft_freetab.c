/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:41:17 by aproust           #+#    #+#             */
/*   Updated: 2023/10/08 16:41:57 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	free_tab(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return ;
	while (str[++i])
		free(str[i]);
	free(str);
	str = 0;
}
