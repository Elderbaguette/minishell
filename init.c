/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:07:43 by aproust           #+#    #+#             */
/*   Updated: 2023/10/24 14:01:20 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_path(t_struct_cmd *struct_cmd, char *av)
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	if (struct_cmd->data->path)
	{
		while (struct_cmd->data->path[++i])
		{
			str = ft_strjoin("/", struct_cmd->args[0]);
			if (!str)
				;
			struct_cmd->cmd[i] = ft_strjoin(struct_cmd->data->path[i], str);
			if (!struct_cmd->cmd[i])
				;
			free(str);
		}
		return ;
	}
	struct_cmd->cmd = ft_calloc(sizeof(char *), 2);
	if (!struct_cmd->cmd)
		return ;
	struct_cmd->cmd[0] = ft_strjoin("/", av);
	if (struct_cmd->cmd[0] == NULL)
		return ;
}

char	*init_tabb(t_data *d, char *str, char **av)
{
	d->i = -1;
	d->i_check = -1;
	while (av[++d->i])
	{
		if (sncmp(av[d->i], ">", 1) == 0 || sncmp(av[d->i], ">>", 2) == 0
			|| sncmp(av[d->i], "<", 1) == 0 || sncmp(av[d->i], "<<", 2) == 0
			|| (d->i > 0 && (sncmp(av[d->i - 1], ">\0", 2) == 0
					|| sncmp(av[d->i - 1], ">>\0", 3) == 0
					|| sncmp(av[d->i - 1], "<\0", 2) == 0
					|| sncmp(av[d->i - 1], "<<\0", 3) == 0)))
			continue ;
		str = ft_strrrjoin(str, av[d->i], d->denv);
	}
	if (!str)
		return (printf("Error : command not found\n"), NULL);
	return (str);
}

int	init_cmd(t_data *data, char **av)
{
	int		i;
	char	*str;
	char	**tabb;

	str = NULL;
	str = init_tabb(data, str, av);
	if (!str)
		return (1);
	tabb = split_coat(str, data->denv, '|');
	i = -1;
	while (data->struct_cmd[++i])
	{
		data->struct_cmd[i]->abs = 0;
		data->struct_cmd[i]->args = ft_split(tabb[i], ' ');
		if (data->struct_cmd[i]->args == NULL)
			return (1);
		if (ft_strchr(data->struct_cmd[i]->args[0], '/'))
			data->struct_cmd[i]->abs = data->struct_cmd[i]->args[0];
		else
			set_path(data->struct_cmd[i], data->struct_cmd[i]->args[0]);
	}
	free(str);
	free_tab(tabb);
	return (0);
}

void	alloc_struct(t_data *data, int len)
{
	int	i;

	i = -1;
	data->struct_cmd = ft_calloc(sizeof(t_struct_cmd *), data->nb_cmd + 1);
	if (!data->struct_cmd)
		return ;
	while (++i < data->nb_cmd)
	{
		data->struct_cmd[i] = ft_calloc(sizeof(t_struct_cmd), 1);
		if (data->struct_cmd[i] == NULL)
			return ;
		if (len != 0)
		{
			data->struct_cmd[i]->cmd = ft_calloc(sizeof(char *), len + 1);
			if (data->struct_cmd[i]->cmd == NULL)
				return ;
		}
		data->struct_cmd[i]->data = data;
	}
}

int	init_struct(t_data *data, char *envp, char **input)
{
	int		len;
	t_data	*data2;

	if (envp)
		data->path = ft_split(envp, ':');
	len = lentab(data->path);
	alloc_struct(data, len);
	if (init_cmd(data, input) == 1)
		return (1);
	data2 = get_singleton(data);
	return (0);
}
