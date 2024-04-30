/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:17:38 by martalop          #+#    #+#             */
/*   Updated: 2024/01/27 15:42:34 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s_trm;
	size_t	i;
	size_t	j;
	int		x;

	i = 0;
	x = 0;
	j = ft_strlen(s1);
	if (!set)
		return (ft_strdup(s1));
	while (ft_strchr(set, (int) s1[i]) != 0 && i < j)
		i++;
	if (s1[i] == '\0')
		return (s_trm = ft_strdup(""));
	while (ft_strchr(set, (int)s1[j - 1]) != 0 && j > i)
		j--;
	s_trm = malloc((j - i + 1) * sizeof(char));
	if (!s_trm)
		return (NULL);
	while (i < j)
		s_trm[x++] = s1[i++];
	s_trm[x] = '\0';
	return (s_trm);
}
//	s_trm = ft_calloc((j - i + 1), sizeof(char));

/*int	main(void)
{
	char const	*s1;
	char const	*set;

	s1 = "aabkobaab";
	set = "ab";
	printf("%s\n", ft_strtrim(s1, set));
	return (0);
}*/
