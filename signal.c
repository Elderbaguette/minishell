/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:56:51 by aproust           #+#    #+#             */
/*   Updated: 2023/10/23 16:56:43 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_sig;

void	hdsignal(int signum)
{
	t_data	*data2;

	data2 = NULL;
	data2 = get_singleton(data2);
	(void)signum;
	close(data2->fd[0]);
	close(data2->fd[1]);
	close(data2->fd_hd[0]);
	close(data2->fd_hd[1]);
	free(data2->str);
	free(data2->buffer);
	get_next_line(-42, data2);
	free_all(data2, -1, 1);
	if (signum == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		exit(130);
	}
	if (signum == SIGQUIT)
		exit(131);
}

void	sig_handler2(int sig)
{
	t_data	*data;

	data = NULL;
	data = get_singleton(data);
	if (sig == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("", 1);
		printf("\n");
		data->sigexi = 130;
	}
	if (sig == SIGQUIT)
	{
		ft_putstr_fd("Quit (core dumped)\n", 2);
		rl_on_new_line();
		rl_replace_line("", 1);
		data->sigexi = 131;
	}
}

void	sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		g_sig = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}
