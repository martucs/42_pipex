/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:56:41 by martalop          #+#    #+#             */
/*   Updated: 2024/01/23 14:37:45 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while ((str1[i] != '\0') || (str2[i] != '\0'))
	{
		if ((str1[i] == str2[i]) && ((size_t) i < n - 1))
			i++;
		else
			return (str1[i] - str2[i]);
	}
	return (str1[i]);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s1;
	const char	*s2;
	const char	*s1_2;
	const char	*s2_2;
	size_t		n;

	s1 = "hola";
	s2 = "holi";
	n = 10 * sizeof(char);
	s1_2 = "hola";
	s2_2 = "holi";
	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d\n", strncmp(s1_2, s2_2, n));
}*/
