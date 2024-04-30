/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:52:49 by martalop          #+#    #+#             */
/*   Updated: 2024/01/26 12:24:18 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*str;
	unsigned char	x;
	int				i;

	str = (char *) s;
	x = (unsigned char) c;
	i = 0;
	while (str[i] != '\0' && str[i] != x)
	{
		i++;
	}
	if (str[i] != x)
		return (0);
	return ((str + i));
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str;
	const char	*str_2;
	int	c;
	
	c = '\0';
	str = "newold";
	str_2 = "newold";
	printf("%s\n", ft_strchr(str, c));
	printf("%s\n", strchr(str_2, c));
	return (0);
}*/
