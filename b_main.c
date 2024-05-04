/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:12:31 by marbaret          #+#    #+#             */
/*   Updated: 2023/10/18 16:24:42 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	replace(t_env *data, char *str)
{
	t_tab		*ex;
	static int	j = -1;

	ex = data->list2;
	while (ex)
	{
		if (ft_strc(str, ex->value) == 0)
		{
			data->stock[++j] = ft_strdup(str);
			ex->value = data->stock[j];
			free(str);
			return (0);
		}
		ex = ex->next;
	}
	free(str);
	return (1);
}

int	handle_export(t_env *data, int i, char **input)
{
	char	*str;
	t_tab	*ex;

	ex = data->list2;
	while (ex)
	{
		str = delguil(input[i]);
		if (ft_strcmp(str, ex->value) == 0
			|| ft_strc(str, ex->value) == 0)
		{
			if (after_equal(str) == 0)
				return (replace(data, str), 1);
			return (free(str), 1);
		}
		free(str);
		ex = ex->next;
	}
	return (0);
}

int	builtins_sequel(char **input, t_env *data, char *str)
{
	if (ft_strcmp(input[0], "cd") == 0)
		return (cd_builtin(input, data), 1);
	else if (ft_strcmp(input[0], "unset") == 0)
	{
		data->k = 0;
		while (input[++data->k])
		{
			str = delguil(input[data->k]);
			if (ft_strchr(str, '='))
				return (free(str), 1);
			unset(data, str);
			free(str);
		}
		return (1);
	}
	return (0);
}

int	is_builtins2(char **input, t_env *data, int fd, t_struct_cmd *scmd)
{
	if (ft_strcmp(input[0], "env") == 0 && !input[1] && check_path(scmd))
		return (print_list(data, fd), 1);
	else if (ft_strcmp(input[0], "echo") == 0)
		return (echoo(input));
	else if (ft_strcmp(input[0], "pwd") == 0)
		return (pwd(input, fd));
	return (0);
}

int	is_builtins1(char **input, t_env *data, t_data *dat)
{
	int		i;
	char	*str;

	i = 0;
	str = 0;
	if (ft_strcmp(input[0], "export") == 0)
	{
		while (input[++i])
		{
			if (cond(input[i]) == 1)
				return (1);
			str = delguil(input[i]);
			if (handle_export(data, i, input) == 1)
				return (free(str), 1);
			export(str, data);
			free(str);
		}
		return (1);
	}
	else if (ft_strcmp(input[0], "exit") == 0)
		return (ft_exit(input, data, dat), 1);
	else if (builtins_sequel(input, data, str))
		return (1);
	return (0);
}
