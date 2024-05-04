/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:46:50 by mathieu           #+#    #+#             */
/*   Updated: 2023/10/18 16:32:12 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	new_env(char **envp, t_env *data)
{
	int	i;

	i = 0;
	data->exported = 1;
	data->b = 0;
	data->env = 0;
	data->to_break = 0;
	data->var = 0;
	data->inistr = 0;
	data->stock = ft_calloc(sizeof(char *), SIZE);
	data->list2 = ft_lstnewstr(envp[i]);
	while (envp[++i])
	{
		add_back_str(data->list2, ft_lstnewstr(envp[i]));
		data->exported++;
	}
}

void	export_sequel(t_env *data, char *var)
{
	add_back_str(data->list2, ft_lstnewstr(var));
	data->exported++;
}

int	ft_strcc(const char *s1, const char *s2)
{
	size_t	i;
	int		n;
	char	*str;

	i = 0;
	while (s2[i++] && s2[i] != '=')
		;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (1);
	str[i] = '\0';
	while (i-- != 0)
		str[i] = s2[i];
	i++;
	while ((s1[i] && str[i]) && s1[i] == str[i])
		i++;
	n = (unsigned char)s1[i] - (unsigned char)str[i];
	return (free(str), n);
}

void	cd_sequel(char **args)
{
	char		*temp;
	char		*str;

	if (args[1][1] && args[1][1] == '/')
	{
		temp = ft_substr(args[1], 1, ft_strlen(args[1]) - 1);
		str = ft_strjoin(getenv("HOME"), temp);
		if (chdir(str) != 0)
			perror("cd : path");
		free (temp);
		free(str);
	}
	else if ((chdir(getenv("HOME")) != 0))
		perror("cd : path");
}
