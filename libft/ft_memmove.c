/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 00:56:02 by martalop          #+#    #+#             */
/*   Updated: 2024/01/29 10:27:19 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t					i;
	unsigned char			*dest;
	unsigned char			*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if ((!dest && !source) || len == 0)
		return (dest);
	if ((dest > source))
	{
		while (len--)
		{
			dest[len] = source[len];
		}
	}
	if ((source > dest))
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src_1[11] = "consectetur";
	char	src_2[11] = "consectetur";
	char	dst[10] = "";
	char	dst_2[10] = "";
	size_t	length = 5 * sizeof(char);

	printf("%s\n", ft_memmove(dst, src_1, length));
	printf("%s\n", memmove(dst_2, src_2, length));
	return (0);
}
*/
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src_1[7] = "hola";
	char	src_2[7] = "hola";
	size_t	length = 4 * sizeof(char);

	printf("%s\n", ft_memmove(src_1 + 1, src_1, length));
	printf("%s\n", memmove(src_2 + 2, src_2, length));
	return (0);
}*/
