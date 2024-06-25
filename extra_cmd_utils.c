/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_cmd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:14:41 by martalop          #+#    #+#             */
/*   Updated: 2024/05/21 15:21:58 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

char	**create_empty_array(void)
{
	char	**arr;

	arr = malloc(sizeof(char *) * 1);
	if (!arr)
		return (NULL);
	arr[0] = ft_strdup("");
	if (!arr[0])
		return (NULL);
	return (arr);
}

char	**join_for_path(char **paths)
{
	int		x;
	char	*tmp;

	x = 0;
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

char	*check_cmd_access(char **paths, char *cmd)
{
	int		x;
	char	*tmp;

	x = 0;
	while (paths[x])
	{
		tmp = ft_strjoin(paths[x], cmd);
		if (!tmp)
			return (NULL);
		if (!access(tmp, X_OK))
			return (tmp);
		free(tmp);
		x++;
	}
	tmp = ft_strdup(cmd);
	return (tmp);
}
