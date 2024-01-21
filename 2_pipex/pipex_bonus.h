s/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:55:12 by seojchoi          #+#    #+#             */
/*   Updated: 2023/08/31 13:27:54 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_envp {
	char	**path;
	char	*access_path;
}t_envp;

typedef struct s_info {
	int		prev_fd[2];
	int		cur_fd[2];
	int		flag;
	int		cmd_size;
	int		cmd_idx;
	char	*infile;
	char	*outfile;
	char	*tmpfile;
	t_envp	envp;
}t_info;

// is_here_doc_bonus
int		is_limiter(char *str, char *limiter);
int		here_doc(char **av, t_info *info);
int		is_here_doc(char *str);
// envp_access_bonus
int		check_is_access(t_envp *envp, char *cmd);
void	get_envp_path(char **ev, t_envp *envp);
// pipe_bonus
void	backup(t_info *info);
void	do_cmd(char *cmd, char **ev, t_info *info);
void	first_pipe(char *infile, char *first_cmd, t_info *info, char **ev);
void	mid_pipe(char *mid_cmd, t_info *info, char **ev);
void	last_pipe(char *outfile, char *last_cmd, t_info *info, char **ev);
// fd_close_bonus
void	close_prev(t_info *info);
void	close_cur(t_info *info);
void	close_n_wait(t_info *info);
// error_bonus
int		cnt_cmd(char *cmd);
void	file_error(char *file_name);
void	command_error(char *cmd);
void	input_error(void);
void	system_error(void);

#endif
