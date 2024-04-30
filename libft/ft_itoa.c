/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:29:53 by martalop          #+#    #+#             */
/*   Updated: 2024/04/06 14:44:55 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>
static int	ft_count_num(int n, int *neg)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		*neg = 1;
	}
	if (n == 0)
		return (i);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_weird_cases(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else
		return (ft_strdup("-2147483648"));
}

char	*ft_itoa(int n)
{
	char	*s;
	int		num;
	int		neg;

	neg = 0;
	num = ft_count_num(n, &neg);
	num = num + neg;
	if (n == 0 || n == -2147483648)
		return (ft_weird_cases(n));
	s = (char *)malloc ((num + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		s[0] = '-';
	}
	s[num] = '\0';
	num--;
	while (n > 0)
	{
		s[num--] = n % 10 + '0';
		n = n / 10;
	}
	return (s);
}

/*#include <stdio.h>

int	main(void)
{
	int	n;

	n = -0;
	printf("%s_\n", ft_itoa(-0));
	return (0);
}*/
