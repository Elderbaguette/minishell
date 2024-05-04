/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:54:36 by aproust           #+#    #+#             */
/*   Updated: 2023/10/23 16:56:29 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_sig;

void	execute(t_struct_cmd *scmd)
{
	int		i;
	t_tab	*cpy;

	scmd->data->env = ft_calloc(sizeof(char *), SIZE);
	if (!scmd->data->env)
		return ;
	cpy = scmd->data->denv->list2;
	i = -1;
	while (cpy)
	{
		scmd->data->env[++i] = cpy->value;
		cpy = cpy->next;
	}
	i = -1;
	while (scmd->cmd[++i])
	{
		if (access(scmd->cmd[i], X_OK) == 0)
			execve(scmd->cmd[i], scmd->args, scmd->data->env);
	}
	if (scmd->abs && access(scmd->abs, X_OK) == 0)
		execve(scmd->abs, scmd->args, scmd->data->env);
	free(scmd->data->env);
	print_error(scmd->data, CMD_ERR, 127, 1);
}

void	start_processing_if(t_data *data, int *fd)
{
	if (data->if_hd == 1)
		fd[0] = if_here_doc(data, fd);
	else
		fd[0] = open(data->infile, O_RDONLY, 0644);
	if (fd[0] == -1)
	{
		ft_close(data->fd);
		ft_close2(data->prev_pipes);
		print_error(data, NULL, 1, 1);
	}
}

void	start_processing(t_data *data, int i, char **input)
{
	int	fd[2];

	fd[1] = data->fd[1];
	fd[0] = data->fd[0];
	exec_wait(data, i);
	if (data->if_status == i + 1)
		start_processing_if(data, fd);
	else if (i != 0)
		fd[0] = data->prev_pipes;
	if (data->outfile[i] || data->outfile2[i])
		start_processing_sequel(fd, data, i);
	ft_dup2(i, fd, data, input);
	ft_close(data->fd);
	ft_close(fd);
	execute(data->struct_cmd[i]);
}

void	handle_pipe_end(t_data *data)
{
	int	i;
	int	status;

	status = 0;
	i = -1;
	if (data->prev_pipes != -1)
		close(data->prev_pipes);
	while (data->struct_cmd[++i])
	{
		waitpid(data->struct_cmd[i]->pid, &status, 0);
		g_sig = WEXITSTATUS(status);
	}
	if (data->sigexi)
		g_sig = data->sigexi;
}

void	execute_cmd(t_data *data, char **input, t_env *denv)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < data->nb_cmd)
	{
		signal(SIGQUIT, &sig_handler2);
		signal(SIGINT, &sig_handler2);
		if (is_builtins1(input, denv, data) == 1)
			continue ;
		++j;
		if (pipe(data->fd) == -1)
			print_error(data, PIPE_ERR, 0, 0);
		data->struct_cmd[i]->pid = fork();
		if (data->struct_cmd[i]->pid == -1)
			print_error(data, FORK_ERR, 0, 0);
		if (data->struct_cmd[i]->pid == 0)
			start_processing(data, j, input);
		if (data->prev_pipes != -1)
			close(data->prev_pipes);
		data->prev_pipes = data->fd[0];
		close(data->fd[1]);
	}
	handle_pipe_end(data);
}
