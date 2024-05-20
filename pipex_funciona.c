/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:01:09 by martalop          #+#    #+#             */
/*   Updated: 2024/05/20 21:42:58 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
//#include <sys/time.h>

char	**prep_cmd_paths(char **env)
{
	int		i;
	int		x;
	char	*tmp;
	char	**paths;

	i = 0;
	x = 0;
	paths = NULL;

	i = 0;
	while (env[i] && !ft_strnstr(env[i], "PATH", 4))
		i++;
	if (!env[i]) // para cuando no encuentra "PATH" en el env
	{
		paths = malloc(sizeof(char *) * 1);
		if (!paths)
			return (NULL);
		paths[0] = ft_strdup("");
		if (!paths[0])
			return (NULL);
		return (paths);
	}
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	while (paths[x])
	{
		tmp = ft_strjoin(paths[x], "/");
		if (!tmp)
			return (free_array(paths), NULL);
		free(paths[x]);
		paths[x] = tmp;
		x++;
	}
	return (paths);
}

char	*find_path(char **paths, char **arr_cmd)
{
	int		x;
	char	*tmp;

	if (arr_cmd[0] == NULL)
	{
		tmp = ft_strdup("");
		if (!tmp)
			return (NULL);
	 	return(tmp);
	}
	x = 0;
	if (!access(arr_cmd[0], X_OK))
	{
		tmp = ft_strdup(arr_cmd[0]);
		if (!tmp)
			return (NULL);
		return (tmp);
	}
	while (paths[x])
	{
		tmp = ft_strjoin(paths[x], arr_cmd[0]);
		if (!tmp)
			return (NULL);
		if (!access(tmp, X_OK)) // tengo acceso
			return (tmp);
		free(tmp); // estoy liberando cada resultado del strjoin
		x++;
	}
	tmp = ft_strdup(arr_cmd[0]);
	if (!tmp)
		return (NULL);
	return (tmp);
}
// if I don't find the command's path, I return the start of the command

char	**get_cmds(char *arg)
{
	char	**array;

	array = ft_split(arg, ' ');
	if (!array)
		return (NULL);
	return (array);
}

t_cmd	*set_command(t_info *info, char *argv)
{
	t_cmd	*cmd;
	
	cmd = malloc(sizeof(t_cmd) * 1);
	if (!cmd)
		return (perror("bad malloc in set_command"), NULL);
	cmd->arr_cmd = get_cmds(argv);
	if (!cmd->arr_cmd)
	{
		free(cmd);
		return (perror("problem spliting argument"), NULL);
	}
	cmd->path = find_path(info->paths, cmd->arr_cmd);
	if (!cmd->path) // solo entra si ha fallado strjoin o ft_strdup
	{
		free_array(cmd->arr_cmd);
		free(cmd);
		perror("problem creating cmd path");
		return (NULL);
	}
	cmd->second = NULL;
	/*	if (argv == info->argv[2])
			cmd->second = NULL;
	else
	{
	//	printf("%p\n", cmd->second);
		cmd->second->arr_cmd = NULL;
		cmd->second->path = NULL;
		printf("%p\n", (cmd->second)->arr_cmd);
		printf("%p\n", cmd->second->path);

		cmd->second->arr_cmd = get_cmds(argv);
		if (!cmd->second->arr_cmd)
		{
			free(cmd);
			return (perror("problem spliting argument"), NULL);
		}
		cmd->second->path = find_path(info->paths, cmd->second->arr_cmd);
		if (!cmd->second->path) // solo entra si ha fallado strjoin o ft_strdup
		{
			free_array(cmd->second->arr_cmd);
//			free(cmd->second);
			perror("problem creating cmd path");
			return (NULL);
		}
	}*/
	return (cmd);
}

int	exec_scnd_cmd(t_info *info, t_cmd *cmd_info, char **env)
{
	int		pid;
	int		fd2;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		fd2 = open(info->out_name, O_CREAT | O_TRUNC | O_RDWR, 420);
		if (fd2 < 1)
		{
			write(2, info->out_name, ft_strlen(info->out_name));
			write(2, ": ", 2);
			perror("");
			exit(1);
		}
		if (dup2(fd2, 1) == -1)
		{
			perror("problem with dup2 of std_out in 2nd command");
			exit(1);
		}
		close(fd2);
		if (dup2(info->pipe_end[0], 0) == -1)
		{
			perror("problem with dup2 of std_in in 2nd command");
			exit(1);
		}
		close(info->pipe_end[0]);
		if (execve(cmd_info->path, cmd_info->arr_cmd, env) == -1)
		{
			write(2, "Command not found: ", 19);
			write(2, cmd_info->path, ft_strlen(cmd_info->path));
			write(2, "\n", 1); // si no pongo esto, no me imprime lo anterior
			exit(1);
		}
	}
	return (0);
}

int	exec_first_cmd(t_info *info, t_cmd *cmd_info, char **env)
{
	int		pid;
	int		fd;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		fd = open(info->in_name, O_RDONLY);
		if (fd < 1)
		{
			write(2, info->in_name, ft_strlen(info->in_name));
			write(2, ": ", 2);
			perror("");
			exit(0);
		}
		if (dup2(fd, 0) == -1)
		{
			perror("problem with dup2 of std_in in 1st command");
			exit(0);
		}
		close(fd);
		if (dup2(info->pipe_end[1], 1) == -1)
		{
			perror("problem with dup2 of std_out in 1st command");
			exit(0);
		}
		close(info->pipe_end[1]);
		if (execve(cmd_info->path, cmd_info->arr_cmd, env) == -1)
		{
			write(2, "Command not found: ", 19);
			write(2, cmd_info->path, ft_strlen(cmd_info->path));
			write(2, "\n", 1);
		}
		exit(0);
	}
	return (0);
}

int	set_info(char **argv, int argc, char **env, t_info *info)
{
	info->in_name = argv[1];
	info->out_name = argv[argc - 1];
	info->paths = prep_cmd_paths(env);
	if (!info->paths)
	{
		perror("problem getting paths");
		return (1);
	}
	info->argv = argv;
	info->env = env;
	info->argc = argc;
	return (0);
}

void	free_t_cmd(t_cmd *cmd)
{
	free_array(cmd->arr_cmd);
	free(cmd->path);
	if ((cmd->second) != NULL)
	{
		free_array(cmd->second->arr_cmd);
		free(cmd->second->path);
		free(cmd->second);
	}
	free(cmd);
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
	if (exec_scnd_cmd(info, cmd->second, info->env) == -1) // fork error
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
	if (!cmd_info1) // solo se cumple si hay error de malloc de 't_cmd' o de split de 'arr_cmd'
	{
		free_array(info->paths);
		return (NULL);
	}
	if (exec_first_cmd(info, cmd_info1, info->env) == -1) // fork error
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
	
	info.pipe_end[0] = 0;
	if (argc != 5)
	{
		write(2, "usage: infile command_1 command_2 outfile\n", 42);
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
	/*cmd_info1 = set_command(info.paths, argv[2]);
	if (!cmd_info1) // solo se cumple si hay error de malloc de 't_cmd' o de split de 'arr_cmd'
	{
		free_array(info.paths);
		return (1);
	}
	if (exec_first_cmd(&info, cmd_info1, env) == -1) // fork error
	{
		free_t_cmd(cmd_info1);
		free_array(info.paths);
		perror("fork problem in cmd1");
		return (1);
	}
	close(info.pipe_end[1]);*/

	if (second_cmd(&info, cmd) == 1)
	{
		return (1);
	}

	/*cmd_info2 = set_command(info.paths, argv[3]);
	if (!cmd_info2)
	{
		free_array(info.paths);
	//	free_t_cmd(cmd_info1);
		perror("problem getting command 2 info");
		return (1);
	}
	if (exec_scnd_cmd(&info, cmd_info2, env) == -1) // fork error
	{
	//	free_t_cmd(cmd_info1);
		free_t_cmd(cmd_info2);
		free_array(info.paths);
		perror("fork problem in cmd2");
		return (1);
	}
	close(info.pipe_end[0]);*/
	wait(NULL);
	wait(NULL);


	free_t_cmd(cmd);
//	free_t_cmd(cmd->second);
	free_array(info.paths);
	return (0);
}
