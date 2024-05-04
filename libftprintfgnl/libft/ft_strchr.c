/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:12 by aproust           #+#    #+#             */
/*   Updated: 2023/03/25 17:28:49 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*true_str;

	i = 0;
	if (!str)
		return (NULL);
	true_str = (char *)str;
	if (c == '\0')
		return (&true_str[ft_strlen(str)]);
	while (true_str[i])
	{
		if (true_str[i] == (char)c)
		{
			return (&true_str[i]);
		}
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     const char *str = "QuoiFeur";
// 	printf("%s", ft_strchr(str, 't' + 256));
// }
