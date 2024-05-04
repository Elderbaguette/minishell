/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:10:16 by aproust           #+#    #+#             */
/*   Updated: 2023/10/21 19:08:28 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_free(char *str)
{
	if (str)
		free(str);
	str = 0;
	return (str);
}

void	free_cmd(t_struct_cmd **struct_cmd)
{
	int	i;

	i = -1;
	if (!struct_cmd)
		return ;
	while (struct_cmd[++i])
	{
		free_tab(struct_cmd[i]->args);
		free_tab(struct_cmd[i]->cmd);
		free(struct_cmd[i]);
	}
	free(struct_cmd);
}

void	free_all(t_data *data, int param, int exi)
{
	t_tab	*cpy;

	free_tab(data->path);
	free_cmd(data->struct_cmd);
	free(data->outfile);
	free(data->outfile2);
	if (exi == 1)
	{
		while (data->denv->list2)
		{
			cpy = data->denv->list2;
			data->denv->list2 = data->denv->list2->next;
			free(cpy);
		}
		free(data->denv->list2);
		free(data->line);
		free_tab(data->input);
		free_tab(data->denv->stock);
		free_tab(data->denv->var);
	}
	if (param >= 0)
		exit(param);
}

void	print_error(t_data *data, char *err_msg, int param, int exit)
{
	if (!err_msg)
		perror("Error");
	else
		ft_putendl_fd(err_msg, 2);
	free_all(data, param, exit);
}
