/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:45:35 by aproust           #+#    #+#             */
/*   Updated: 2023/03/23 15:20:44 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pu(unsigned long int n, unsigned long int sb, const char *base)
{
	if (n < sb)
		return (ft_putcharfd(base[n % sb], 1));
	if (n >= sb)
		return (pu(n / sb, sb, base) + ft_putcharfd(base[n % sb], 1));
	return (0);
}
