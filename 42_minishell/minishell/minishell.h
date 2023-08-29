/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:58:19 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/30 21:36:54 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include "parse/parse.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_data
{
	t_arg			*list;
	t_type_counter	*count_type;
	char			*line;
	char			**envp;
	char			**ex_path;
	char			**heredoc;
	char			**command;
	char			**redirection;
	int				signal_status;
	int				**all_pipe_fd;
	int				fd;
	int				pipe_c;
	int				*pipe_id;
	int				exit_status;
	char			*here_line;
	int				*here_fd;
	int				*exec_fd;
	int				here_count;
	char			*main_here_line;
	int				main_here_size;
	char			**dollars;
	char			**dollar_line;
	int				sig_flag;
	int				error_flag;
	int				dollar_flag;
	int				heredoc_flag;
	int				sig_handler_flag;
	int				executor_flag;
}					t_data;

t_data				g_data;

void				start(void);

int					ft_parse(void);
int					error_check(void);
int					initialize_pipe(void);
void				execute(void);

int					ft_strcmp(char *s1, char *s2);

void				ft_cd(void);
void				ft_pwd(void);
void				ft_env(void);
void				ft_echo(void);
void				ft_unset(void);
void				ft_export(void);
void				ft_slash_controller(int sig);
int					builtin(void);
int					ft_strlen2(char **a);

void				check_way(void);
void				ft_command_line(void);

void				check_dollar_exit(void);

void				ft_execve(void);
void				exec_pipe(void);
void				exec_shell(int status);
void				exec_redir(int status);

int					pipe_counter(void);
void				create_tubes(void);

void				ft_heredoc_line(void);
void				ft_dollars_line(void);
void				ft_special_func(int j);
void				ft_exit(t_arg *data);
void				ft_free_all(void);
void				ft_sig_handler(int sig);

void				*ft_export_path(void);
void				ft_export(void);
void				ft_delenv(char **envp, int j, int flag);
void				ft_addenv(char **envp, int j, int flag);
int					env_counter(char **envp);
int					special_parse(int i, char *prev_arg);
char				*ft_find_env(char *arg);
int					ft_path_founder(char **envp, char *name);
void				upenv(char **envp, int j, int flag);
char				**create_cpy_env(char **envp);
void				freeliazer(t_arg *temp);
void				signal_exit(void);
void				initialize_fork(void);
void				ft_free_command_redirection(void);
void				close_fd(int id);
int					quot_parse(char *str);
int					is_space(char s);
#endif
