/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aproust <aproust@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:21:40 by aproust           #+#    #+#             */
/*   Updated: 2023/10/23 15:56:43 by aproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libftprintfgnl/libftprintfgnl.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <termios.h>
# include <curses.h>
# include <term.h>
# include <linux/limits.h>

# define MALLOC_ERR "Error: while trying to malloc"
# define FORK_ERR "Error: fork failed"
# define PIPE_ERR "Error: pipe failed"
# define CMD_ERR "Error: command not found"
# define SIZE 4096

typedef struct data	t_data;

typedef struct t_struct_cmd
{
	char	**cmd;
	char	**args;
	char	*abs;
	pid_t	pid;
	t_data	*data;
}	t_struct_cmd;

typedef struct s_tab
{
	char			*name;
	char			*value;
	struct s_tab	*next;
}	t_tab;

typedef struct env
{
	t_tab	*list2;
	char	**env;
	int		envlen;
	int		exported;
	int		to_break;
	int		i_sc;
	int		j_sc;
	int		n;
	int		b;
	int		j;
	int		k;
	char	c;
	int		spc;
	char	**var;
	int		startc;
	char	*path;
	int		jump;
	int		ifvar;
	char	*inistr;
	char	**stock;
}	t_env;

typedef struct data
{
	char			*line;
	char			**input;
	char			**path;
	char			*infile;
	char			**outfile;
	char			**outfile2;
	char			**env;
	char			*str;
	char			*buffer;
	int				nb_cmd;
	int				prev_pipes;
	int				here_doc_fd;
	int				fd[2];
	int				fd2[2];
	int				fd_hd[2];
	int				if_status;
	int				if_hd;
	int				i;
	int				j;
	int				i_check;
	int				sigexi;
	t_env			*denv;
	t_struct_cmd	**struct_cmd;
}	t_data;

typedef struct utils
{
	int		i;
	int		j;
	int		n;
	char	*str;
}	t_utils;

typedef struct utils2
{
	int		i;
	int		a;
	int		j;
	char	*str;
}	t_utils2;

typedef struct singleton
{
	t_data	*daton;
}	t_singleton;

int		ft_strc(const char *s1, const char *s2);
void	set_env(char **envp, t_env *data, int n);
int		process(int n, char **path, char **av, char **envp);
void	print_path(char *str);
int		start_process(t_data *data, char **av, char **envp, int i);
int		process(int n, char **path, char **av, char **envp);
int		init_struct(t_data *data, char *envp, char **input);
void	print_error(t_data *data, char *err_msg, int param, int exit);
void	free_all(t_data *data, int param, int exit);
void	execute_cmd(t_data *data, char **input, t_env *denv);
void	execute(t_struct_cmd *struct_cmd);
int		if_here_doc(t_data *data, int *fd);
void	free_cmd(t_struct_cmd **struct_cmd);
char	*get_word(char *path, int param);
int		pipex(char **input, t_env *denv, char *line);
char	*ft_strdel(char *str, char *del);
char	*ft_strrrjoin(char *s1, char *s2, t_env *denv);
int		is_builtins1(char **input, t_env *data, t_data *dat);
void	print_list(t_env *data, int fd);
void	add_back_str(t_tab *list, t_tab *new);
t_tab	*ft_lstnewstr(char *content);
void	if_one(t_tab *ex2, t_env *data);
void	if_multi(t_tab *ex, t_tab *ex2, t_env *data, t_tab *env);
void	if_first(t_tab *ex2, t_env *data);
void	env_mod(t_env *data, int i);
void	unset_opti(t_tab *ex, t_tab *ex2, t_env *data, t_tab *env);
int		pwd(char **args, int fd);
int		echoo(char **args);
int		unset(t_env *data, char *args);
char	*delguil(char *input);
int		export(char *args, t_env *data);
bool	cd_builtin(char **args, t_env *data);
void	points(t_env *data, char *str, char **args);
void	slash(t_env *data, char *str, char **args);
void	ft_close(int *fd);
void	ft_close2(int fd);
void	ft_dup2(int i, int *fd, t_data *data, char **input);
void	export_sequel(t_env *data, char *var);
void	new_env(char **envp, t_env *data);
char	*str_trunc(char *str, int param);
int		ft_arraychr(const char *str, int c);
char	*str_trunc(char *str, int param);
char	*if_expound(char *av, t_env *denv);
void	sig_handler(int sig);
int		after_equal(char *str);
int		ft_strcc(const char *s1, const char *s2);
char	*ft_free(char *str);
char	**split_coat(char *s, t_env *denv, char c);
char	*delguil2(char	*input);
int		wordcount2(char *s);
void	cd_sequel(char **args);
void	ft_exit(char **input, t_env *denv, t_data *data);
int		is_builtins2(char **input, t_env *data, int fd, t_struct_cmd *scmd);
int		cond(char *input);
char	*search_path(t_env *denv);
void	sig_handler2(int sig);
void	hdsignal(int signum);
int		check_path(t_struct_cmd *scmd);
void	exec_wait(t_data *data, int i);
int		start_processing_sequel(int *fd, t_data *data, int i);
t_data	*get_singleton(t_data *data);

#endif
