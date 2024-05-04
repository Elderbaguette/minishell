/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expound.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:35:19 by aproust           #+#    #+#             */
/*   Updated: 2023/10/14 18:01:07 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_sig;

char	*if_dollar_sequel(t_env *denv, char *str, char *sstr, char *av)
{
	int	i;

	i = -1;
	if (sncmp(av, "?", 1) == 0)
	{
		sstr = ft_itoa(g_sig);
		str = ft_strrjoin(str, sstr);
		free(sstr);
		denv->jump = 1;
		denv->ifvar = 1;
	}
	if (denv->ifvar == 0)
	{
		while (av[++i] && av[i] != ' ' && av[i] != '$' && av[i] != '"')
			;
		denv->jump = i;
	}
	return (str);
}

char	*charjoin(char *str, char c, int param)
{
	int		i;
	char	*nstr;

	i = 0;
	nstr = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!nstr)
		return (NULL);
	while (str && str[i])
	{
		nstr[i] = str[i];
		i++;
	}
	nstr[i] = c;
	nstr[i + 1] = '\0';
	if (param == 0)
		free(str);
	return (nstr);
}

char	*if_dollar(char *av, t_env *denv, char *str)
{
	char	*sstr;
	t_tab	*ex;

	if (!av[0])
		return (ft_strrjoin(str, " $"));
	denv->ifvar = 0;
	ex = denv->list2;
	while (ex->next)
	{
		sstr = str_trunc(ex->value, 0);
		if (sncmp(av, sstr, ft_strlen(sstr)) == 0 && (av[ft_strlen(sstr)] == ' '
				|| av[ft_strlen(sstr)] == '\0' || av[ft_strlen(sstr)] == '$'
				|| av[ft_strlen(sstr)] == '"'))
		{
			denv->jump = ft_strlen(sstr);
			free(sstr);
			sstr = str_trunc(ex->value, 1);
			str = ft_strrjoin(str, sstr);
			denv->ifvar = 1;
		}
		free(sstr);
		ex = ex->next;
	}
	return (if_dollar_sequel(denv, str, sstr, av));
}

char	*if_expound(char *av, t_env *denv)
{
	int		j;
	char	*str;

	str = NULL;
	j = -1;
	denv->jump = 0;
	if (!ft_strchr(av, '$'))
		return (av);
	while (av[++j])
	{
		if (av[j] == '\'')
		{
			while (av[++j] && av[j] != '\'')
				str = charjoin(str, av[j], 0);
		}
		else if (av[j] == '$')
		{
			str = if_dollar(&av[j + 1], denv, str);
			j += denv->jump;
		}
		else
			str = charjoin(str, av[j], 0);
	}
	return (str);
}

int	ft_arraychr(const char *str, int c)
{
	int		i;
	char	*true_str;

	i = 0;
	if (!str)
		return (0);
	true_str = (char *)str;
	if (c == '\0')
		return (ft_strlen(str));
	while (true_str[i])
	{
		if (true_str[i] == (char)c)
			return (i);
		i++;
	}
	return (ft_strlen(str));
}
