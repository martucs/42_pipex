/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:43:55 by martalop          #+#    #+#             */
/*   Updated: 2024/01/24 13:10:02 by martalop         ###   ########.fr       */
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub_s;

	i = (size_t) start;
	j = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(&s[i]))
	{
		len = ft_strlen(&s[i]);
	}
	sub_s = malloc(sizeof(char) * (len + 1));
	if (!sub_s)
		return (NULL);
	while ((i < (start + len)) && (start < ft_strlen(s)))
	{
		sub_s[j] = s[i];
		i++;
		j++;
	}
	sub_s[j] = '\0';
	return (sub_s);
}

/*#include <stdio.h>

int	main(void)
{
	char const	*s;
	unsigned int	start;
	size_t			len;
	char	*res_substr;

	s = "holapp";
	start = 1;
	len = 7;
	res_substr = ft_substr(s, start, len);
	printf("%s_\n", res_substr);
	//printf("length de sub_s: %zu\n", ft_strlen(res_substr));
	return (0);
}*/
