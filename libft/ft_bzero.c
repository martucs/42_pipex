/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:38:15 by martalop          #+#    #+#             */
/*   Updated: 2024/01/13 16:39:52 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t			i;
	unsigned char	zero;

	zero = '\0';
	string = (unsigned char *)s;
	i = 0;
	if (n != 0)
	{
		while (i < n)
		{
			string[i] = zero;
			i++;
		}
	}
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[] = "hola";
	char	str_2[] = "hola";
	size_t n = 5 * sizeof(char);

	printf("%s\n", str);
	ft_bzero(str, n);
	printf("ft_bzero: %s\n", str);
	
	printf("%s\n", str_2);
	bzero(str_2, n);
	printf("bzero: %s\n", str_2);
	return (0);
}*/
