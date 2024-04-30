/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:59:53 by martalop          #+#    #+#             */
/*   Updated: 2024/04/25 18:06:17 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strj;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	strj = malloc((sizeof(char)) * (s1_len + s2_len + 1));
	if (!strj)
		return (NULL);
	while (i < s1_len)
	{
		strj[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
		strj[i++] = s2[j++];
	strj[i] = '\0';
//	free((char *)s1);
	return (strj);
}
/*int	main(void)
{
	char const	*s1;
	char const	*s2;

	s1 = "tripouille";
	s2 = "42";
	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}*/
