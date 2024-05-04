/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 14:02:27 by aproust           #+#    #+#             */
/*   Updated: 2023/10/23 15:45:47 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	start_processing_sequel(int *fd, t_data *data, int i)
{
	if (data->outfile[i])
	{
		close(fd[1]);
		fd[1] = open(data->outfile[i], O_RDWR | O_CREAT | O_TRUNC, 0644);
	}
	else if (data->outfile2[i])
	{
		close(fd[1]);
		fd[1] = open(data->outfile2[i], O_RDWR | O_CREAT | O_APPEND, 0644);
	}
	if (fd[1] == -1)
	{
		ft_close(data->fd);
		close(fd[0]);
		print_error(data, NULL, 1, 1);
	}
	return (0);
}

void	ft_close2(int fd)
{
	if (fd > 0)
		close(fd);
}

void	ft_close(int *fd)
{
	if (fd[0])
		close(fd[0]);
	if (fd[1])
		close(fd[1]);
}

void	ft_dup2(int i, int *fd, t_data *data, char **input)
{
	int	n_fd;

	n_fd = 1;
	if (i != 0 || data->if_status == i + 1)
		dup2(fd[0], STDIN_FILENO);
	if (data->outfile[i] || data->outfile2[i] || i != data->nb_cmd - 1)
	{
		n_fd = fd[1];
		dup2(fd[1], STDOUT_FILENO);
	}
	if (is_builtins2(input, data->denv, n_fd, data->struct_cmd[i]) == 1)
	{
		ft_close(data->fd);
		ft_close(fd);
		free_all(data, 0, 1);
	}
}

void	exec_wait(t_data *data, int i)
{
	int	waiter;

	waiter = 0;
	if (i == data->nb_cmd - 1)
	{
		while (waiter != 99999)
		{
			ft_strlen("waiting...");
			waiter++;
		}
	}
}
