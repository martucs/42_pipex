/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:44:08 by martalop          #+#    #+#             */
/*   Updated: 2024/04/25 21:33:29 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

char	**split_add(char *str, char c);
char	**prep_cmd_paths(char **env);
char	*find_command(char **paths, char **argv);
char	**get_cmds(char *arg);
char	**free_array(char **array);
int		execute_cmd(char *argv, char **env);

long	start_time;

#endif
