/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:42:37 by aproust           #+#    #+#             */
/*   Updated: 2023/10/22 14:02:48 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strrjoin_sequel(char *s1, int len, char *s2, t_env *denv)
{
	size_t	i;
	char	*str;

	str = ft_calloc(sizeof(char), (len + ft_strl((char *)s2) + 1 + denv->spc));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	if (i != 0)
	{
		denv->spc = 1;
		str[i] = ' ';
	}
	return (str);
}

char	*ft_strrrjoin(char *s1, char *s2, t_env *denv)
{
	char	*str;
	size_t	len;
	int		i;

	denv->spc = 0;
	i = 0;
	if (!s2)
		return (NULL);
	if (s1)
		denv->spc = 1;
	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	len = ft_strl((char *)s1);
	str = ft_strrjoin_sequel(s1, len, s2, denv);
	if (!str)
		return (NULL);
	i = 0;
	while (s2[i])
		str[len++ + denv->spc] = s2[i++];
	str[len + denv->spc] = '\0';
	free((char *)s1);
	return (str);
}
