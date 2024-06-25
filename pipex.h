/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:44:08 by martalop          #+#    #+#             */
/*   Updated: 2024/05/30 14:27:26 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>

typedef struct s_info
{
	int		pipe_end[2];
	int		pid1;
	int		pid2;
	char	*in_name;
	char	*out_name;
	char	**paths;
	char	**argv;
	char	**env;
	int		argc;
}	t_info;

typedef struct s_cmd
{
	char			**arr_cmd;
	char			*path;
	struct s_cmd	*second;
}	t_cmd;

char	**prep_cmd_paths(char **env);
char	*find_path(char **paths, char **arr_cmd);
char	**get_cmds(char *arg);
char	**free_array(char **array);
t_cmd	*set_command(t_info *info, char *argv);
void	free_t_cmd(t_cmd *cmd);
int		set_info(char **argv, int argc, char **env, t_info *info);
void	print_t_info(t_info info);
void	last_free(t_cmd *cmd, char **paths);
char	**create_empty_array(void);
char	**join_for_path(char **paths);
char	*check_cmd_access(char **paths, char *cmd);
void	cmd_not_found(t_cmd *cmd_info);
void	perror_message(char *message, int flag);

#endif
