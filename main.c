/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 10:58:09 by aproust           #+#    #+#             */
/*   Updated: 2023/10/24 13:54:30 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig;

void	minishell(t_env *denv, char **input, char *line)
{
	while (1)
	{
		signal(SIGINT, &sig_handler);
		signal(SIGQUIT, SIG_IGN);
		line = readline("➜ ");
		signal(SIGINT, SIG_IGN);
		if (!line)
		{
			free(line);
			rl_clear_history();
			break ;
		}
		else if (line[0] != '\0')
		{
			add_history(line);
			line = if_expound(line, denv);
			input = split_coat(line, denv, ' ');
			pipex(input, denv, line);
			free(line);
			free_tab(input);
		}
		else if (line[0] == '\0')
			rl_on_new_line();
	}
}

int	main(int ac, char **av, char **env)
{
	t_env	denv;
	t_tab	*cpy;
	char	*line;
	char	**input;

	line = 0;
	input = 0;
	new_env(env, &denv);
	minishell(&denv, input, line);
	while (denv.list2)
	{
		cpy = denv.list2;
		denv.list2 = denv.list2->next;
		free(cpy);
	}
	ft_putendl_fd("exit", 1);
	free_tab(denv.var);
	free_tab(denv.stock);
	rl_clear_history();
	return ((void)ac, (void)av, 0);
}
