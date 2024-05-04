/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:05:12 by aproust           #+#    #+#             */
/*   Updated: 2023/10/18 15:57:12 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_data	*get_singleton(t_data *data)
{
	static t_data	*data2;

	if (!data)
		return (data2);
	data2 = data;
	return (data2);
}

void	when_here_doc(t_data *data, int *fd)
{
	t_data	*data2;

	data->str = ft_strjoin(data->infile, "\n");
	if (!data->str)
		print_error(data, NULL, 0, 0);
	while (1)
	{
		data2 = get_singleton(data);
		signal(SIGINT, hdsignal);
		signal(SIGQUIT, hdsignal);
		write(0, "> ", 2);
		data->buffer = get_next_line(0, data);
		if (!data->buffer)
		{
			ft_putstr_fd("warning: heredoc delimited by EOF, wanted: ", 2);
			ft_putstr_fd(data->str, 2);
			break ;
		}
		if (ft_strcmp(data->buffer, data->str) == 0)
			break ;
		ft_putstr_fd(data->buffer, fd[1]);
		free(data->buffer);
	}
	free(data->buffer);
	free(data->str);
}

int	if_here_doc(t_data *data, int *fd)
{
	if (pipe(fd) == -1)
		print_error(data, NULL, 0, 0);
	data->fd_hd[0] = fd[0];
	data->fd_hd[1] = fd[1];
	data->buffer = 0;
	when_here_doc(data, fd);
	close(fd[1]);
	fd[1] = data->fd[1];
	return (fd[0]);
}
