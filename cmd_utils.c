/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:05:43 by martalop          #+#    #+#             */
/*   Updated: 2024/05/30 14:32:41 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

char	*find_path(char **paths, char **arr_cmd)
{
	int		x;
	char	*tmp;

	x = 0;
	if (arr_cmd[0] == NULL)
	{
		tmp = ft_strdup("");
		return (tmp);
	}
	if (arr_cmd[0][0] == '/')
	{
		tmp = ft_strdup(arr_cmd[0]);
		return (tmp);
	}
	if (arr_cmd[0][0] == '.' && arr_cmd[0][1] == '/')
	{
		tmp = ft_strdup(arr_cmd[0]);
		return (tmp);
	}
	tmp = check_cmd_access(paths, arr_cmd[0]);
	return (tmp);
}

char	**prep_cmd_paths(char **env)
{
	int		i;
	char	**paths;

	i = 0;
	paths = NULL;
	while (env[i] && !ft_strnstr(env[i], "PATH", 4))
		i++;
	if (!env[i])
	{
		paths = create_empty_array();
		if (!paths)
			return (NULL);
		return (paths);
	}
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		return (NULL);
	paths = join_for_path(paths);
	if (!paths)
		return (NULL);
	return (paths);
}

char	**get_cmds(char *arg)
{
	char	**array;

	array = ft_split(arg, ' ');
	if (!array)
		return (NULL);
	return (array);
}

int	set_info(char **argv, int argc, char **env, t_info *info)
{
	info->pipe_end[0] = 0;
	info->pid1 = 2;
	info->pid2 = 3;
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
	if (!cmd->path)
	{
		free_array(cmd->arr_cmd);
		free(cmd);
		perror("problem creating cmd path");
		return (NULL);
	}
	cmd->second = NULL;
	return (cmd);
}
