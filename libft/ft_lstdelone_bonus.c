/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 14:42:06 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 21:02:10 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

/*static void	del(void *content)
{
	free(content);
}
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

/*int	main()
{
	t_list	*node;
	char	*s;

	s = (char *)malloc(sizeof(char) * 12);
	if (!s)
		return (0);
//	printf("%zu\n", sizeof(s)); // por que es menor a 12 si el malloc no da error???
	ft_strlcpy(s, "to be freed", 12);
	node = malloc(sizeof(t_list));
	if (!node)
		return (free(s), 0);
	node->content = s;
	node->next = NULL;
	printf("%s\n", node->content);
	ft_lstdelone(node, del);
//	printf("%s", node->content);
	return (0);
}*/

// si hago:
// s = (char *)malloc(sizeof(char) * 12);
// s = "to be freed";
// esto me causa PERDIDA DE MEMORIA -> malloc error: "pointer being freed was not allocated"
// por que? prq estoy perdiendo el lugar donde apuntaba el espacio reservado con malloc para decirle que ahora 's' apunte a un string literal, que esta en otro lugar de memoria (no he utilizado malloc para ese espacio).
//
// Luego en la funcion 'ft_lstdelone' lo quiero liberar pero no he hecho malloc en esa direccion, osea que no tiene sentido y da error.
//
