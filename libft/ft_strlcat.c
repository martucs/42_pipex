/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:30:49 by martalop          #+#    #+#             */
/*   Updated: 2024/02/01 19:06:44 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while ((dst[i] != '\0') && (i < dstsize))
		i++;
	if ((dstsize != 0) && (i < (dstsize - 1)))
	{
		while ((i + j < dstsize - 1) && (src[j] != '\0'))
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = '\0';
	}
	while (src[j] != '\0')
		j++;
	return (i + j);
}

/*int	main(void)
{
	char	lib_dst[30] = "This is a test$";
	char 	mar_dst[30] = "This is a test$";
	char	src[30] = "add this$";
	size_t	dstsize = 16;

	printf("dstsize: %zu\n", dstsize);
	printf("Lib Return value: %zu\n", strlcat(lib_dst, src, dstsize));
	printf("Lib dst: __%s__\n", lib_dst);
	printf("\n");

	printf("Marta value     : %zu\n", ft_strlcat(mar_dst, src, dstsize));
	printf("Mar dst: __%s__\n", mar_dst);

	return (0);
}*/
