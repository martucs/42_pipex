/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:52:55 by martalop          #+#    #+#             */
/*   Updated: 2024/05/30 15:09:03 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

void	cmd_not_found(t_cmd *cmd_info)
{
	write(2, "Command not found: ", 19);
	write(2, cmd_info->path, ft_strlen(cmd_info->path));
	write(2, "\n", 1);
	exit(127);
}

void	perror_message(char *message, int flag)
{
	if (flag)
		write(2, ": ", 2);
	perror(message);
	exit(1);
}

char	**free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
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

void	last_free(t_cmd *cmd, char **paths)
{
	free_t_cmd(cmd);
	free_array(paths);
}
