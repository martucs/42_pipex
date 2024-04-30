/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:48:45 by martalop          #+#    #+#             */
/*   Updated: 2024/01/29 12:04:51 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	len_s;
	size_t	i;
	char	new_line;

	i = 0;
	len_s = ft_strlen(s);
	new_line = '\n';
	write (fd, &s[i], (sizeof(char) * len_s));
	write (fd, &new_line, sizeof(new_line));
}

/*int	main(void)
{
	char	*s;
	int		fd;

	s = "hola";
	fd = 1;
	ft_putstr_fd(s, fd);
	return (0);
}
*/
