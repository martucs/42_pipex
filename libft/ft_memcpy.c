/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:14:25 by martalop          #+#    #+#             */
/*   Updated: 2024/01/27 16:02:23 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char	destination[] = "\0";
	//char	destination_1[] = "\0";

	//char source[7] = "hola";
	size_t num = 3 * sizeof(char);

	printf("%s\n", ft_memcpy(((void *) 0), ((void *) 0), num));
	printf("%s\n", memcpy(((void *) 0), ((void *) 0), num));
	return (0);
}*/
