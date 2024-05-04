/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:05:19 by aproust           #+#    #+#             */
/*   Updated: 2023/10/23 15:56:58 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_cmd(char **input)
{
	int	i;
	int	c;

	i = -1;
	c = 0;
	while (input[++i])
	{
		if (sncmp(input[i], "|\0", 2) == 0)
			c++;
	}
	return (c);
}

int	check_redir(char **input, int i)
{
	if ((sncmp(input[i], "<", 1) == 0 && (!input[i][1] && !input[i + 1]))
	|| (sncmp(input[i], "<<", 2) == 0 && (!input[i][2] && !input[i + 1]))
	|| (sncmp(input[i], ">", 1) == 0 && (!input[i][1] && !input[i + 1]))
	|| (sncmp(input[i], ">>", 2) == 0 && (!input[i][2] && !input[i + 1])))
		return (1);
	return (0);
}

void	init_of(t_data *data, char **ip, int i)
{
	int	fd;

	if (sncmp(ip[i], ">", 1) == 0 && sncmp(ip[i], ">>", 2) != 0)
	{
		if (data->outfile[data->nb_cmd - count_cmd(&ip[i]) - 1])
		{
			fd = open(data->outfile[data->nb_cmd - count_cmd(&ip[i]) - 1],
					O_RDWR | O_CREAT | O_TRUNC, 0644);
			close(fd);
		}
		data->outfile[data->nb_cmd - count_cmd(&ip[i]) - 1]
			= &ip[i + (ft_strlen(ip[i]) == 1)][(ft_strlen(ip[i]) > 1)];
	}
	else if (sncmp(ip[i], ">>", 2) == 0 && sncmp(ip[i], ">>>", 3) != 0)
	{
		if (data->outfile2[data->nb_cmd - count_cmd(&ip[i]) - 1])
		{
			fd = open(data->outfile[data->nb_cmd - count_cmd(&ip[i]) - 1],
					O_RDWR | O_CREAT | O_APPEND, 0644);
			close(fd);
		}
		data->outfile2[data->nb_cmd - count_cmd(&ip[i]) - 1]
			= &ip[i + (ft_strlen(ip[i]) == 2)][(ft_strlen(ip[i]) > 2) * 2];
	}
}

int	init_if(t_data *data, char **ip)
{
	int		i;

	i = -1;
	while (ip[++i])
	{
		if (check_redir(ip, i))
			return (printf("syntax error near unexpected token newline\n"), 1);
		else if ((sncmp(ip[i], "<", 1) == 0) && sncmp(ip[i], "<<", 2) != 0)
		{
			data->infile = &ip[i + (ft_strlen(ip[i]) == 1)]
			[(ft_strlen(ip[i]) > 1)];
			data->if_status = data->nb_cmd - count_cmd(&ip[i]);
		}
		else if (sncmp(ip[i], "<<", 2) == 0 && sncmp(ip[i], "<<<", 3) != 0)
		{
			data->if_hd = 1;
			data->if_status = data->nb_cmd - count_cmd(&ip[i]);
			data->infile = &ip[i + (ft_strlen(ip[i]) == 2)]
			[(ft_strlen(ip[i]) > 2) + (ft_strlen(ip[i]) > 2)];
		}
		init_of(data, ip, i);
	}
	return (0);
}

int	pipex(char **input, t_env *denv, char *line)
{
	t_data	data;
	char	*envp;

	data.path = NULL;
	data.nb_cmd = count_cmd(input) + 1;
	data.prev_pipes = -1;
	data.if_hd = 0;
	data.input = input;
	data.line = line;
	data.denv = denv;
	data.infile = 0;
	data.outfile = ft_calloc(sizeof(char *), data.nb_cmd + 1);
	data.outfile2 = ft_calloc(sizeof(char *), data.nb_cmd + 1);
	data.if_status = -1;
	data.sigexi = 0;
	if (init_if(&data, input))
		return (1);
	envp = search_path(denv);
	if (init_struct(&data, envp, input) == 1)
		return (free_all(&data, -1, 0), 1);
	execute_cmd(&data, input, denv);
	free_all(&data, -1, 0);
	return (0);
}
