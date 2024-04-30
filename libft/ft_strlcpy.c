/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:51:41 by martalop          #+#    #+#             */
/*   Updated: 2024/01/22 20:54:34 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i =  0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (src[i] != '\0' && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

/*int	main(void)
{
	char		dst[20] = "holabola";
	char		dst_2[20] = "holabola";
	const char	src[] = "";
	size_t	dstsize;

	dstsize = 4 * sizeof(char);

	printf("dstsize: %zu\n", dstsize);
	printf("dst: %s\n", dst);
	printf("%zu\n", ft_strlcpy(dst, src, dstsize));
	printf("dst: %s\n", dst);

	printf("dst_2: %s\n", dst_2);
	printf("%zu\n", strlcpy(dst_2, src, dstsize));
	printf("dst_2: %s\n", dst_2);
	return (0);
}*/
