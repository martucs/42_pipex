/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:53:52 by martalop          #+#    #+#             */
/*   Updated: 2024/01/29 10:28:37 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stddef.h>
//#include <stdlib.h>
#include <errno.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*variable;
	size_t	i;

	i = 0;
	variable = malloc(count * size);
	if (!variable)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (i < (count * size))
	{
		variable[i] = '\0';
		i++;
	}
	return ((void *)variable);
}

//variable = malloc(count * sizeof(size));

/*#include <stdio.h>

int	main(void)
{
	size_t	count = 42;
	size_t	size = sizeof(int);

	printf("%s\n", ft_calloc(count, size));
	printf("%s\n", calloc(count, size));
	return (0);
}*/
