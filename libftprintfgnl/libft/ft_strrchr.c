/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:46 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 13:31:47 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *) s;
	if (c == '\0')
		return (&str[ft_strlen(str)]);
	i = ft_strlen(str);
	while (i != -1)
	{
		if (str[i] == (char) c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}

// int main(void)
// {
// 	printf("%s\n", ft_strrchr("truc", 't'));
// 	return (0);
// }
