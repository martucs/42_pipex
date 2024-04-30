/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:01:09 by martalop          #+#    #+#             */
/*   Updated: 2024/04/29 19:49:13 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>
#include <sys/time.h>

long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	time.tv_sec %= 31556925;
	return (time.tv_sec * 1e6 + time.tv_usec);
}

char	**prep_cmd_paths(char **env)
{
	int	i;
	int	x;
	char	*tmp;
	char	**paths;

	i = 0;
	x = 0;
	paths = NULL;
	while (!ft_strnstr(env[i], "PATH", 4))
	{
		i++;
	}
//	printf("\nline %d is: %s\n", i + 1, env[i]);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return ( NULL);
	while (paths[x])
	{
		tmp = ft_strjoin(paths[x], "/");
		if (!tmp)
			return (free_array(paths));
		free(paths[x]);
		paths[x] = tmp;
		x++;
	}
	return (paths);
}

char	*find_path(char **paths, char **arr_cmd)
{
	int	x;
	char	*tmp;

	x = 0;
	while (paths[x])
	{
		tmp = ft_strjoin(paths[x], arr_cmd[0]);
		if (!tmp)
			return (NULL);
		if (!access(tmp, X_OK))
		{
//			printf("I have access to %s\n", tmp);
			return (tmp);
		}
		else
//			printf("I don't have access to %s\n", tmp);
		free(tmp); // estoy borrando cada resultado del strjoin
		x++;
	}
	return (NULL);
}

char	**get_cmds(char *arg)
{
	char	**array;

	array = ft_split(arg, ' ');
	if (!array)
		return (NULL);
	return (array);
}

int	execute_cmd(char *argv, char **env)
{
	int		i;
	int		x;
	int		pid;
	char	**arr_cmd;
	char	**paths;
	char	*right_path;

	i = 0;
	x = 0;
	paths = prep_cmd_paths(env); // hago split de todos los paths + el '/' y devuelvo char **
	if (!paths)
		return (perror("problem getting commands"), 1);
	while (paths[x])
	{
		i++;
		x++;
	}
	arr_cmd = get_cmds(argv); // split del segundo argumento (primer comando)
	if (!arr_cmd)
		return (perror("problem spliting argument"), 1);
	right_path = find_path(paths, arr_cmd); // juntar el path con el comando base y comprobar acceso para cada path
	if (!right_path)
		return (1);
	pid = fork();
	if (pid == 0)
	{
		execve(right_path, arr_cmd, env);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int	x;
	
	start_time = gettime();
	x = 0;
	if (argc < 5)
		return (1);
	if (execute_cmd(argv[2], env))
		return (perror("execute_cmd 1 problem"), 1);
	if (execute_cmd(argv[3], env))
		return (perror("execute_cmd 2 problem"), 1);
	wait(NULL); // espera a que termine cualquiera de los dos procesos
	wait(NULL);
	return (0);
}
