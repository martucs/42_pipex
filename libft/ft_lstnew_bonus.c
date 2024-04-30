/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:32:27 by martalop          #+#    #+#             */
/*   Updated: 2024/03/29 14:41:45 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
//	printf("adress of 'node':             %p\n", node);
//	printf("adress of the string in node: %p\n", node);
	return (node);
}

/*int	main()
{
	t_list	*res;
	char	*content;

	content = "hola";
	res = ft_lstnew(content);
	printf("%p\n", res);
	return(0);
}*/

// todas las direcciones (la de node, la del contenido de node(una string) y la de res) son IGUALES
