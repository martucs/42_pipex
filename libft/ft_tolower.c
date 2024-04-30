/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:40:08 by martalop          #+#    #+#             */
/*   Updated: 2024/01/17 13:42:50 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch > 64 && ch < 91)
		return ((ch + 32));
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c;
	int	c_2;

	c = 'Z';
	c_2 = 'Z';
	printf("%c\n", ft_tolower(c));
	printf("%c\n", tolower(c_2));
	return (0);
}*/
