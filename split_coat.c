/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_coat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 17:19:10 by aproust           #+#    #+#             */
/*   Updated: 2023/10/14 15:38:14 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_substr2(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	clearmemory2(char **str)
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

char	**split_coat_sequel(char *s, t_env *denv, char **str, char *tmp)
{
	int			start;

	start = denv->i_sc;
	while (s[denv->i_sc] != denv->c && s[denv->i_sc])
	{
		if (s[denv->i_sc] && s[denv->i_sc] == '\'' && s[denv->i_sc + 1])
		{
			while (s[++denv->i_sc + 1] && s[denv->i_sc + 1] != '\'')
				;
		}
		else if (s[denv->i_sc] && s[denv->i_sc] == '\"' && s[denv->i_sc + 1])
		{
			while (s[++denv->i_sc + 1] && s[denv->i_sc + 1] != '\"')
				;
		}
		denv->i_sc++;
	}
	str[denv->j_sc] = ft_substr2(tmp, start, denv->i_sc - start);
	if (!str[denv->j_sc++])
		clearmemory2(str);
	return (str);
}

char	**split_coat(char *s, t_env *denv, char c)
{
	char	**str;
	char	*tmp;

	denv->i_sc = 0;
	denv->j_sc = 0;
	denv->c = c;
	if (denv->c == ' ')
		tmp = ft_strdup(s);
	else
		tmp = delguil2(s);
	str = malloc(sizeof(char *) * (wordcount2(s) + 1));
	if (!str || !tmp)
		return (NULL);
	while (s[denv->i_sc])
	{
		while (s[denv->i_sc] == denv->c && s[denv->i_sc])
			denv->i_sc++;
		if (s[denv->i_sc] == '\0')
			break ;
		split_coat_sequel(s, denv, str, tmp);
	}
	free(tmp);
	str[denv->j_sc] = 0;
	denv->i_sc = -1;
	return (str);
}
