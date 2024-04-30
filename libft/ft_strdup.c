/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 12:26:35 by martalop          #+#    #+#             */
/*   Updated: 2024/01/23 14:43:03 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	indx;

	indx = 0;
	while (s[indx] != '\0')
		indx++;
	return (indx);
}
*/
#include "libft.h"
#include <errno.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	size_t	s1_len;

	i = 0;
	s1_len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (s1_len + 1));
	if (!s2)
	{
		errno = ENOMEM;
		return (NULL);
	}
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*s1;

	s1 = "sunny";
	printf("%s\n", ft_strdup(s1));
	printf("%s\n", strdup(s1));
	return (0);
}*/
