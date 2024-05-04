/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:49 by aproust           #+#    #+#             */
/*   Updated: 2022/11/14 17:55:49 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	charcheck(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	k = -1;
	if (!s1)
		return (NULL);
	j = ft_strlen(s1);
	while (charcheck(s1[i], (char *)set) == 1)
		i++;
	while (charcheck(s1[j - 1], (char *)set) == 1)
		j--;
	if (set == NULL || !s1)
		return (0);
	if (i >= j)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (j - i + 1));
	if (!str || j - i + 1 <= 0)
		return (NULL);
	while (++k + i < j)
		str[k] = s1[k + i];
	str[k] = '\0';
	return (str);
}

// int	main (void)
// {
// 	printf("%s", ft_strtrim("   watashi wa aruberu  ", " u"));
// }
