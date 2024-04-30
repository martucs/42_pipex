/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_simon.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:12:55 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 21:02:42 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *info)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = info;
	node->next = NULL;
	return (node);
}

/*void	ft_lstadd_front(t_list **lst, t_list *new)
{
//	if (!*lst)
//		*lst = new;
	new->next = *lst; 
	*lst = new;
}*/
/*
int	main(void)
{
	char info1[15] = "This is a test";
	t_list	*node1;

	node1 = ft_lstnew(info1);
	printf("%p\n", node1);
	printf("%s\n", node1->content);
	printf("%p\n", node1->next);
	free(node1);
	return (0);
}*/

/*int	main(void)
{
	char info1[15] = "This is a test";
	char info2[99] = "de la muerte";
	t_list	*node1;
	t_list	*node2;
	t_list	*list = NULL;

	node1 = ft_lstnew(info1);
	node2 = ft_lstnew(info2);
	ft_lstadd_front(&list, node1);
	ft_lstadd_front(&list, node2);
	printf("%s\n", list->content);
	printf("%s\n", list->next->content);
	free(node2);
	free(node1);
	return (0);
}*/
