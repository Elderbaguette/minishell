/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 20:43:59 by mathieu           #+#    #+#             */
/*   Updated: 2023/10/14 14:00:44 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strc(const char *s1, const char *s2)
{
	size_t	i;
	int		n;
	char	*str;

	i = 0;
	while (s2[i++] && s2[i] != '=')
		;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (1);
	str[i] = '\0';
	while (i-- != 0)
		str[i] = s2[i];
	i++;
	while ((s1[i] && str[i + 1] && str[i]) && s1[i] == str[i])
		i++;
	n = (unsigned char)s1[i] - (unsigned char)str[i];
	return (free(str), n);
}

void	print_list(t_env *data, int fd)
{
	t_tab	*ex;

	ex = data->list2;
	while (ex)
	{
		ft_putendl_fd(ex->value, fd);
		ex = ex->next;
	}
}

t_tab	*ft_lstnewstr(char *content)
{
	t_tab	*l1;

	l1 = (t_tab *)malloc(sizeof(*l1));
	if (!l1)
		return (NULL);
	l1->value = content;
	l1->next = NULL;
	return (l1);
}

void	add_back_str(t_tab *list, t_tab *new)
{
	t_tab	*str;

	str = list;
	if (!list)
	{
		str = new;
		return ;
	}
	while (str->next)
		str = str->next;
	str->next = new;
	new->next = NULL;
}

char	*delguil(char	*input)
{
	char	*str;
	int		i;
	int		n;

	n = 0;
	i = -1;
	while (input[++i])
	{
		if (input[i] != 34 && input[i] != 39)
			n++;
	}
	i = -1;
	str = ft_calloc(sizeof(char), n + 1);
	if (!str)
		return (NULL);
	n = 0;
	while (input[++i])
	{
		if (input[i] != 34 && input[i] != 39)
			str[n++] = input[i];
	}
	str[n] = '\0';
	return (str);
}
