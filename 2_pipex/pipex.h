/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojchoi <seojchoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 20:55:12 by seojchoi          #+#    #+#             */
/*   Updated: 2023/07/26 13:44:02 by seojchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_info {
	char	**path;
	char	*access_path;
	int		fd[2];
}t_info;

// do_cmd
int		check_is_access(t_info *info, char *cmd);
void	do_cmd(char *cmd, t_info *info, char **ev);
void	first_cmd(char *infile, char *cmd1, t_info *info, char **ev);
void	second_cmd(char *outfile, char *cmd2, t_info *info, char **ev);
// error
int		cnt_str(char *str);
void	command_error(char *cmd);
void	file_error(char *file_name);
void	input_error(void);
void	system_error(void);

#endif
