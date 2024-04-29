/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:01:09 by martalop          #+#    #+#             */
/*   Updated: 2024/04/26 11:38:55 by martalop         ###   ########.fr       */
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
//		printf("path %d: %s\n", i, paths[x]);
		i++;
		x++;
	}
	arr_cmd = get_cmds(argv); // split del segundo argumento (primer comando)
	if (!arr_cmd)
		return (perror("problem spliting argument"), 1);
	right_path = find_path(paths, arr_cmd); // juntar el path con el comando base y comprobar acceso para cada path
	if (!right_path)
		return (1);
	printf("Creating child at: %ld\n", gettime() - start_time);
	pid = fork();
	if (pid == 0)
	{
		printf("hi from child %d at: %ld\n", getpid(), gettime() - start_time);
		execve(right_path, arr_cmd, env);
		exit(0);
	}
	printf("Finish creating %d at: %ld\n", pid, gettime() - start_time);
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
	printf("Despues del wait %ld\n", gettime() - start_time);
	wait(NULL);
	printf("Despues del wait %ld\n", gettime() - start_time);
	printf("bye from parent at: %ld\n", gettime() - start_time);
	return (0);
}

// aunque le enviamos "./pipex infile.c "cat infile.c" "ls -l" adios"
// ejecuta casi a la vez los dos comandos/procesos pero la ejecucion de "cat" acaba antes que la de "ls -l"
// si le enviamos ./pipex infile.c "ls -l" "cat infile.c" adios
// tambien nos imprime el cat primero a pesar de que el "ls -l" ha empezado primero a ejecutarse
//
