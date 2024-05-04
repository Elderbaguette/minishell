/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:01 by aproust           #+#    #+#             */
/*   Updated: 2022/11/14 17:55:01 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(fd, s, i);
}

// int main (void)
// {
//     int fd = 1;
//     char *s = "Machin truc bidule";
//     ft_putstr_fd(s, fd);
// }
