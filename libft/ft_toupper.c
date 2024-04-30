/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 12:45:43 by martalop          #+#    #+#             */
/*   Updated: 2024/01/17 13:36:59 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch > 96 && ch < 123)
		return ((ch - 32));
	else
		return (c);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	int	c;
	int	c_2;

	c = 49;
	c_2 = 49;
	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c_2));
	return (0);
}*/
