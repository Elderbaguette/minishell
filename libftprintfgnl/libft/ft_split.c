/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 17:55:08 by aproust           #+#    #+#             */
/*   Updated: 2023/10/11 17:13:16 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clearmemory(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

size_t	wordcount(char const *s, char c)
{
	size_t	i;
	size_t	j;

	j = 1;
	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;
	size_t	start;

	i = 0;
	j = 0;
	str = malloc(sizeof(char *) * wordcount(s, c));
	if (!str || !s)
		return (free(str), NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] == '\0')
			break ;
		start = i;
		while (s[i] != c && s[i])
			i++;
		str[j] = ft_substr(s, start, i - start);
		if (!str[j++])
			clearmemory(str);
	}
	str[j] = 0;
	return (str);
}

// int	main()
// {
// 	// ft_split("  d dj dk", ' ');
// 	char **ret = ft_split(NULL, ' ');
// 	(void)ret;
// 	// printf("---> (%s)", ret[0]);
// }
