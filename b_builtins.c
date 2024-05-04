/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_builtins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:35:44 by mathieu           #+#    #+#             */
/*   Updated: 2023/10/18 16:34:57 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(char **args, int fd)
{
	char	cwd[256];

	if (lentab(args) == 1)
	{
		getcwd(cwd, sizeof(cwd));
		ft_putendl_fd(cwd, fd);
		return (1);
	}
	return (0);
}

int	echoo(char **args)
{
	if (!args[1])
		return (printf("\n"), 1);
	if (ft_strcmp(args[1], "-e" ) == 0 || ft_strcmp(args[1], "--version" ) == 0
		|| ft_strcmp(args[1], "--help" ) == 0 || ft_strcmp(args[1], "-E" ) == 0)
		return (1);
	return (0);
}

int	unset(t_env *data, char *args)
{
	t_tab	*ex;
	t_tab	*ex2;
	t_tab	*env;

	env = data->list2;
	ex2 = data->list2;
	ex = data->list2;
	if (!args)
		return (1);
	while (env->next && ft_strcc(args, env->value) != 0)
		env = env->next;
	if (!env->next && ft_strcc(args, env->value) != 0)
		return (1);
	ex = ex->next;
	if (data->exported > 0)
		unset_opti(ex, ex2, data, env);
	return (0);
}

int	export(char *args, t_env *data)
{
	static int	j = -1;
	int			i;
	int			a;

	i = -1;
	a = 0;
	if (!args)
		return (1);
	if (!data->var)
		data->var = ft_calloc(sizeof(char *), SIZE);
	data->var[++j] = ft_calloc(sizeof(char), ft_strlen(args) + 2);
	if (!data->var)
		return (1);
	while (args[++i])
	{
		if (args[i] == '=')
			a = 1;
		data->var[j][i] = args[i];
	}
	if (a == 0)
		return (1);
	export_sequel(data, data->var[j]);
	return (0);
}

bool	cd_builtin(char **args, t_env *data)
{
	t_tab	*cpy;

	if (!args[1])
	{
		cpy = data->list2;
		while (cpy && sncmp(cpy->value, "HOME=", 5) != 0)
			cpy = cpy->next;
		if (sncmp(cpy->value, "HOME=", 5) == 0)
			return (chdir(&cpy->value[5]), true);
		else
			return (printf("cd : HOME not set\n"), true);
	}
	else if (lentab(args) < 3)
	{
		if (args[1] == NULL || args[1][0] == '~' || args[1][0] == '-')
			cd_sequel(args);
		else if (chdir(args[1]) != 0)
			perror("cd : path");
		return (true);
	}
	return (false);
}
