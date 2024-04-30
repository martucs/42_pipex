/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 10:39:08 by martalop          #+#    #+#             */
/*   Updated: 2024/01/23 15:52:18 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stddef.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (str[i] != (unsigned char)c && i + 1 < n)
	{
		i++;
	}
	if ((unsigned char)c == str[i] && n > 0)
		return (&str[i]);
	return (NULL);
}
// yo devuelvo null
// paco devuelve la direccion de memoria de tab[3] = \xff\xff\xff1
/*int    main(void)
{
    int tab[6] = {0, 1, 2, 3, 4, 5};
    printf("%s\n", (char *)ft_memchr(tab, 2, 4));
    return (0);
}
*/
/*#include <stdio.h>
#include <string.h>

int    main(void)
{
    const void    *s;
    int            c;
    size_t        n;

    s = "hzlaz";
    c = '\0';
    n = 5 * sizeof(char);
    printf("%s\n", ft_memchr(s, c, n));
    printf("%s\n", memchr(s, c, n));
    return (0);
}*/
