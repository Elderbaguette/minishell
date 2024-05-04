/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:35 by aproust           #+#    #+#             */
/*   Updated: 2022/11/20 12:04:03 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char ft_toupper(unsigned int d, char toto)
// {
// 	(void)i;
//     if (toto >= 97 &&  toto <= 122)
//     {
//         toto = toto - 32;
//     }
//     return(toto);
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main ()
// {
// 	printf("%s", ft_strmapi("Pablito", ft_toupper));
// }
