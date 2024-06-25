/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:01:09 by martalop          #+#    #+#             */
/*   Updated: 2024/05/31 18:32:59 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

int	exec_scnd_cmd(t_info *info, t_cmd *cmd_info)
{
	int		fd2;

	info->pid2 = fork();
	if (info->pid2 == -1)
		return (1);
	if (info->pid2 == 0)
	{
		fd2 = open(info->out_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd2 < 1)
		{
			write(2, info->out_name, ft_strlen(info->out_name));
			perror_message("", 1);
		}
		if (dup2(fd2, 1) == -1)
			perror_message("problem with dup2 of std_out in 2nd command", 0);
		close(fd2);
		if (dup2(info->pipe_end[0], 0) == -1)
			perror_message("problem with dup2 of std_in in 2nd command", 0);
		close(info->pipe_end[0]);
		if (execve(cmd_info->path, cmd_info->arr_cmd, info->env) == -1)
			cmd_not_found(cmd_info);
	}
	return (0);
}

int	exec_first_cmd(t_info *info, t_cmd *cmd_info)
{
	int		fd;

	info->pid1 = fork();
	if (info->pid1 == -1)
		return (1);
	if (info->pid1 == 0)
	{
		fd = open(info->in_name, O_RDONLY);
		if (fd < 1)
		{
			write(2, info->in_name, ft_strlen(info->in_name));
			perror_message("", 1);
		}
		if (dup2(fd, 0) == -1)
			perror_message("problem with dup2 of std_in in 1st command", 0);
		close(fd);
		if (dup2(info->pipe_end[1], 1) == -1)
			perror_message("problem with dup2 of std_out in 1st command", 0);
		close(info->pipe_end[1]);
		close(info->pipe_end[0]);
		if (execve(cmd_info->path, cmd_info->arr_cmd, info->env) == -1)
			cmd_not_found(cmd_info);
	}
	return (0);
}

int	second_cmd(t_info *info, t_cmd *cmd)
{
	cmd->second = set_command(info, info->argv[3]);
	if (!cmd->second)
	{
		free_array(info->paths);
		free_t_cmd(cmd);
		perror("problem getting command 2 info");
		return (1);
	}
	if (exec_scnd_cmd(info, cmd->second) == -1)
	{
		free_t_cmd(cmd->second);
		free_t_cmd(cmd);
		free_array(info->paths);
		perror("fork problem in cmd2");
		return (1);
	}
	close(info->pipe_end[0]);
	return (0);
}

t_cmd	*first_cmd(t_info *info)
{
	t_cmd	*cmd_info1;

	cmd_info1 = set_command(info, info->argv[2]);
	if (!cmd_info1)
	{
		free_array(info->paths);
		return (NULL);
	}
	if (exec_first_cmd(info, cmd_info1) == -1)
	{
		free_t_cmd(cmd_info1);
		free_array(info->paths);
		perror("fork problem in cmd1");
		return (NULL);
	}
	close(info->pipe_end[1]);
	return (cmd_info1);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_info	info;
	int		exit_status;

	if (argc != 5)
	{
		write(2, "pipex usage: infile command_1 command_2 outfile\n", 48);
		return (1);
	}
	if (set_info(argv, argc, env, &info) == 1)
		return (1);
	if (pipe(info.pipe_end) == -1)
	{
		free_array(info.paths);
		return (perror("problem creating pipe\n"), 1);
	}
	cmd = first_cmd(&info);
	if (!cmd)
		return (1);
	if (second_cmd(&info, cmd) == 1)
		return (1);
	waitpid(info.pid1, NULL, 0);
	waitpid(info.pid2, &exit_status, 0);
	last_free(cmd, info.paths);
	return (WEXITSTATUS(exit_status));
}
