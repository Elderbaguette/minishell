/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_unset_opti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:08:03 by mathieu           #+#    #+#             */
/*   Updated: 2023/10/17 13:29:00 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	after_equal(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
		{
			if (str[i + 1] != '\0')
				return (0);
		}
	}
	return (1);
}

void	if_one(t_tab *ex2, t_env *data)
{
	ex2->value = NULL;
	free(ex2);
	data->exported--;
	data->b = 0;
	data->to_break = 1;
	data->list2 = NULL;
}

void	if_first(t_tab *ex2, t_env *data)
{
	while (ex2->next->next)
	{
		ex2->value = ex2->next->value;
		ex2 = ex2->next;
	}
	ex2->value = ex2->next->value;
	free(ex2->next);
	ex2->next = NULL;
	data->exported--;
	data->to_break = 1;
}

void	if_multi(t_tab *ex, t_tab *ex2, t_env *data, t_tab *env)
{
	while (ex)
	{
		if (ex->value == env->value)
		{
			ex2->next = ex->next;
			free(ex);
			data->exported--;
			data->to_break = 1;
			break ;
		}
		ex = ex->next;
		ex2 = ex2->next;
	}
}

void	unset_opti(t_tab *ex, t_tab *ex2, t_env *data, t_tab *env)
{
	while (ex2)
	{
		data->j++;
		if (data->exported == 1 && ex2->value == env->value)
		{
			if_one(ex2, data);
			break ;
		}
		else if (data->exported > 1)
		{
			if (ex2->value == env->value)
				if_first(ex2, data);
			else
				if_multi(ex, ex2, data, env);
		}
		if (data->to_break == 1)
			break ;
	}
}
