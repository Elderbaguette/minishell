/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_coat_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:19:49 by aproust           #+#    #+#             */
/*   Updated: 2023/10/11 17:22:35 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wordcount2_sequel(t_utils2 *data, char *s)
{
	while (s[data->i] && (s[data->i] != '\"' && s[data->i] != '\''))
	{
		if (s[data->i] == ' ' && data->a == 0)
		{
			data->a++;
			data->j++;
		}
		else
			data->a = 0;
		data->i++;
	}
	if (s[data->i] && s[data->i] == '\'')
	{
		while (s[++data->i] && s[data->i] != '\'')
			;
		if (s[data->i] == ' ')
			data->j++;
	}
	else if (s[data->i] && s[data->i] == '\"')
	{
		while (s[++data->i] && s[data->i] != '\"')
			;
		if (s[data->i] == ' ')
			data->j++;
	}
}

int	wordcount2(char *s)
{
	t_utils2	data;

	data.a = 0;
	data.j = 0;
	if (!s)
		return (0);
	data.i = 0;
	while (s[data.i])
	{
		if (data.i)
			data.i++;
		while (s[data.i] && s[data.i] == ' ')
			data.i++;
		if (s[data.i] == '\0')
			break ;
		wordcount2_sequel(&data, s);
		data.j++;
	}
	return (data.j);
}

char	*delguil_sequel(char *input, t_utils *data)
{
	if (input[data->i] == '\"')
	{
		while (input[data->i] && input[data->i + 1])
		{
			data->i++;
			if (input[data->i] != '\"' && input[data->i])
				data->str[data->n++] = input[data->i];
			else
				break ;
		}
	}
	else if (input[data->i] == '\'')
	{
		while (input[data->i] && input[data->i + 1])
		{
			data->i++;
			if (input[data->i] != '\'' && input[data->i])
				data->str[data->n++] = input[data->i];
			else
				break ;
		}
	}
	return (input);
}

char	*delguil2(char	*input)
{
	t_utils	data;

	data.n = 0;
	data.i = -1;
	while (input[++data.i])
		data.n++;
	data.i = -1;
	data.str = ft_calloc(sizeof(char), data.n + 2);
	if (!data.str)
		return (NULL);
	data.n = 0;
	while (input[++data.i])
	{
		if (input[data.i] != '\"' && input[data.i] != '\'')
			data.str[data.n++] = input[data.i];
		input = delguil_sequel(input, &data);
	}
	data.str[data.n] = '\0';
	return (data.str);
}
