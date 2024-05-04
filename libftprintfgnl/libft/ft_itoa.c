/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:52:18 by aproust           #+#    #+#             */
/*   Updated: 2022/11/21 11:38:36 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_itoa_the_sequel(int nb, int a, int i, char *str)
{
	if (nb < 0)
	{
		nb = -nb;
		str[i] = '-';
		i = a - 1;
		while (i >= 1)
		{
			str[i] = nb % 10 + '0';
			nb = nb / 10;
			i--;
		}
	}
	else
	{
		i = a - 1;
		while (i >= 0)
		{
			str[i] = nb % 10 + '0';
			nb = nb / 10;
			i--;
		}
	}
	str[a] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		a;
	int		nb;

	i = 0;
	a = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = n;
	if (nb < 0)
	{
		nb = nb * (-1);
		a++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		a++;
	}
	str = malloc(sizeof(char) * (a + 1));
	if (!str)
		return (NULL);
	return (ft_itoa_the_sequel(n, a, i, str));
}

// int main(void)
// {
//    printf("%s\n", ft_itoa(100));
// }
