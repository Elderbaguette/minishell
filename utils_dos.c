/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:02:14 by aproust           #+#    #+#             */
/*   Updated: 2023/10/20 14:18:40 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_trunc(char *str, int param)
{
	int		i;
	int		j;
	char	*new_str;

	i = -1;
	j = -1;
	new_str = 0;
	while (str[++i] && str[i] != '=')
		;
	if (param == 0)
	{
		new_str = ft_calloc(sizeof(char), i + 1);
		i = -1;
		while (str[++i] && str[i] != '=')
			new_str[i] = str[i];
		return (new_str);
	}
	i++;
	while (str[i + ++j])
		;
	new_str = ft_calloc(sizeof(char), j + 1);
	j = -1;
	while (str[i + ++j])
		new_str[j] = str[j + i];
	return (new_str);
}

void	ft_exit(char **input, t_env *data, t_data *dat)
{
	int	nb;

	if (input[1][0] >= '0' || input[1][0] <= '9')
	{
		if (lentab(input) == 1)
			nb = 0;
		else if (lentab(input) == 2)
			nb = ft_atoi(input[1]);
		else
		{
			ft_putstr_fd("exit: too many arguments\n", 1);
			return ;
		}
		free(data->env);
		rl_clear_history();
		nb = nb % 256;
		free_all(dat, nb, 1);
	}
	else
	{
		printf("exit: %s: numeric argument required\n", input[1]);
		exit(2);
	}
}

int	cond(char *input)
{
	char	*str;
	int		i;

	i = 0;
	str = str_trunc(input, 0);
	if (((str[i] >= 48 && str[i] <= 57) || input[i] == '='))
		return (printf("export: `%s': not a valid identifier\n", input),
			free(str), 1);
	i++;
	while (str[++i])
	{
		printf("%c\n", str[i]);
		if ((str[i] >= 65 && str [i] <= 90)
			|| (str[i] >= 97 && str[i] <= 122)
			|| str[i] == 39 || str[i] == 34
			|| (str[i] >= 48 && str [i] <= 57))
			;
		else
			return (printf("export: `%s': not a valid identifier\n", str),
				free(str), 1);
	}
	free(str);
	return (0);
}

char	*search_path(t_env *denv)
{
	t_tab	*cpy;
	char	*str;

	str = NULL;
	cpy = denv->list2;
	while (cpy)
	{
		if (cpy->value && sncmp(cpy->value, "PATH=", 5) == 0)
			str = &cpy->value[5];
		cpy = cpy->next;
	}
	return (str);
}

int	check_path(t_struct_cmd *scmd)
{
	int	i;

	i = -1;
	while (scmd->cmd[++i])
	{
		if (access(scmd->cmd[i], F_OK) == 0)
		{
			printf("path:%s\n", scmd->cmd[i]);
			return (1);
		}
	}
	return (0);
}
