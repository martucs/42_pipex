/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:51:07 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 21:01:59 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
//	while((*lst) != NULL)
//	{
//		printf("%s\n", (*lst)->content);
//		(*lst) = (*lst)->next;
//	}

	/*t_list *curr;
	
	curr = *lst;
	new->next = curr;
	curr = new;
	while(curr != NULL)
	{
		printf("%s\n", curr->content);
		curr = curr->next;
	}*/ 
	// es mejor de esta manera para el futuro
}

/*int	main()
{
	t_list	*list;
	t_list	*ptr_to_node2; // creo este puntero prq el '%p' de printf recibe un void * y 'node2' solo es de tipo t_list
	t_list	node1;
	t_list	node2;
	t_list	node_to_be_added;
	char	*s;
	char	*s2;
	char	*s3;

	s = "hol";
	s2 = "adios";
	s3= "b";
	node1.content = s;
	node1.next = &node2;

	node2.content = s2;
	node2.next = NULL;

	node_to_be_added.content = s3;
	node_to_be_added.next = NULL;
	
	list = &node1;
	ptr_to_node2 = &node2; 

	printf("BEFORE \n");

	printf("%p\n", list);
	printf("%s\n", list->content);
	printf("%p\n", list->next);// esta y la de abajo deberian ser iguales
	printf("%p\n", ptr_to_node2);
	printf("%s\n", node2.content); // esta y la de abajo deberian ser iguales
	printf("%s\n", list->next->content);
	printf("%p\n", list->next->next); // deberia ser NULL

//	ft_lstadd_front(&list, &node_to_be_added);

//	printf("AFTER \n");

//	printf("%p\n", list);
//	printf("%s\n", list->content);
//	printf("%s\n", list->next->content);
//	printf("%s\n", list->next->next->content);
//	printf("%p\n", list->next->next->next);

	return (0);
}

int	main()
{
	t_list	*stack;
	t_list	*node;
	char	*str;

	str = (char *)malloc(sizeof(char) * 12);
	if (!str)
		return (0);
	ft_strlcpy(str, "to be freed", 12);
	node = malloc(sizeof(t_list));
	if (!node)
		return (free(str), 0);
	node->content = str;
	node->next = NULL;
	stack = node;

	printf("%p\n", stack);
	
	
	printf("%p\n", list->next);// esta y la de abajo deberian ser iguales
	printf("%p\n", ptr_to_node2);
	printf("%s\n", node2.content); // esta y la de abajo deberian ser iguales
	printf("%s\n", list->next->content);
	printf("%p\n", list->next->next); // deberia ser NULL


	return (0);
}*/
