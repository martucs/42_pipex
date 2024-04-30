/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:36:25 by martalop          #+#    #+#             */
/*   Updated: 2024/01/29 17:47:30 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	len_s;
	size_t	i;

	i = 0;
	len_s = ft_strlen(s);
	write (fd, &s[i], (sizeof(char) * len_s));
}

/*int	main(void)
{
	char	*s;
	int		fd;

	s = "hola";
	fd = 2;
	ft_putstr_fd(s, fd);
	return (0);
}*/
