/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:05:46 by martalop          #+#    #+#             */
/*   Updated: 2024/02/03 20:03:35 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*static char	f(unsigned int num, char c)
{
	(void)num;
	//printf("------%c\n", c);
	if (c)
	{
		c = c + 1;
	}
	//printf("------%c\n", c);
	return (c);
}*/

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*str;

	i = 0;
	if (!f || !s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char const	*s;

	s = "hello";
	printf("%s\n", ft_strmapi(s, f));
	return (0);
}*/
