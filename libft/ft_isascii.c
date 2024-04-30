/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 19:39:12 by martalop          #+#    #+#             */
/*   Updated: 2024/01/10 10:53:42 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
		return (1);
	return (0);
}

/*int	ft_isascii(int c)
{
	return (c >= 0 && c < 128);
}
#include <stdio.h>

int	main()
{
	printf("%d\n" ,ft_isascii(6));

	return (0);
}*/
