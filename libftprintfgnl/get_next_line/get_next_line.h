/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 22:34:27 by pdosso-d          #+#    #+#             */
/*   Updated: 2023/10/21 18:15:09 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdint.h>
# include "../../minishell.h"

typedef struct data	t_data;

char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strrjoin(const char *s1, const char *s2);
int		ft_strl(char *str);
void	*ft_calloc(size_t elemCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);
void	*ft_memset2(void *s, int c, size_t n);
char	*get_next_line(int fd, t_data *data);

#endif
