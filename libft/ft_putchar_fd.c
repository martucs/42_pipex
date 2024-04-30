/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:21:37 by martalop          #+#    #+#             */
/*   Updated: 2024/01/29 11:30:50 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, sizeof(c));
}

/*int	main(void)
{
	char	c;
	int		fd;

	c = 'c';
	fd = 2;
	ft_putchar_fd(c, fd);
	return (0);
}*/
