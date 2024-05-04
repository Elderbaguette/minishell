/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:29:37 by aproust           #+#    #+#             */
/*   Updated: 2022/11/16 14:46:01 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	j;

	i = 0;
	res = 0;
	j = 0;
	while ((str[i] && str[i] == ' ') || (str[i] && str[i] >= 9 && str[i] <= 13))
		i++;
	if ((str[i] && str[i] == '-') || (str[i] && str[i] == '+'))
	{
		if (str[i] == '-')
			j++;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (j % 2 == 0)
		return (res);
	else
		return (-res);
}

// int main (void)
// {
//     printf("Test1%d\n", ft_atoi(" -2147483648"));
//     printf("Test2%d\n", atoi(" -2147483648"));
// }
