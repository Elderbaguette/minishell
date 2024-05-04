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

#include "ft_printf.h"

int	ps(char *s)
{
	int	i;

	if (!s)
		return (write(1, "(null)", 6));
	i = ft_strlen(s);
	return (write(1, s, i));
}

// int main (void)
// {
//     int fd = 1;
//     char *s = "Machin truc bidule";
//     ft_putstr_fd(s, fd);
// }
