/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:05:29 by martalop          #+#    #+#             */
/*   Updated: 2024/01/23 14:40:48 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	x;
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	x = (unsigned char) c;
	tmp = b;
	while (i < len)
	{
		tmp[i] = x;
		i++;
	}
	return (b);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "hello bye";
	int		num = '1';
	size_t	length = 4 * sizeof(char);

	printf("%s\n", str);
	printf("%zu\n", length);
	printf("%s", ft_memset(str, num, length));
	return (0);
}*/

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	unsigned char	temp[100] = "asdkfjsadjfkas";
	//unsigned char	temp_2[] = "hello bye";
	unsigned char	temp_2[100] = "asdkfjsadjfkas";
	int				num = '1';
	size_t			length = 1 * sizeof(char);

	printf( "%s\n", memset(temp, num, length));
	printf( "%s\n", ft_memset(temp_2, num, length));
	//printf("Lo de la libreria standard : %s\n", tmp);
	return (0);
}*/
