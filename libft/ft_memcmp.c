/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 11:11:16 by martalop          #+#    #+#             */
/*   Updated: 2024/01/28 18:57:58 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	if (i < n)
	{
		while ((str1[i] == str2[i]) && (i < (n -1)))
			i++;
		if (i < n)
			return ((int)(str1[i] - str2[i]));
		else
			return (0);
	}
	else
		return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s1;
	const char	*s2;
	const char	*s1_1;
	const char	*s2_1;
	size_t		n;

	s1 = "abcd\0efgxyz";
	s2 = "abcd\0efgxyz";
	s1_1 = "abcdefgxyz";
	s2_1 = "abcdefgxyz";
	n = 15 * sizeof(char);
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1_1, s2_1, n));
	return (0);
}*/
