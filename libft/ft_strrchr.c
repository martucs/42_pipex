/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:14:19 by martalop          #+#    #+#             */
/*   Updated: 2024/01/26 12:11:31 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
/*#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	indx;

	indx = 0;
	while (s[indx] != '\0')
		indx++;
	return (indx);
}*/

char	*ft_strrchr(const char *s, int c)
{
	char			*str;
	unsigned char	x;
	int				i;

	str = (char *) s;
	x = (unsigned char) c;
	i = ft_strlen(str);
	while (i > 0 && str[i] != x)
	{
		i--;
	}
	if (str[i] == x)
		return ((str + i));
	else
		return (0);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s;
	const char	*s_2;
	int	c;

	s = "teste";
	s_2 = "teste";
	c = 'x';
	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s_2, c));
	return (0);
}*/
