/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:23:38 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 21:02:50 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if(!(*lst))
	{
		(*lst) = new;
	}
	else
	{
		tmp = (*lst);
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = new;
	}
}

/*int	main()
{
	t_list	*list;
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	*node4;
	t_list	*tmp;
	char	*s;
	char	*s2;
	char	*s3;
	char	*s4;

	s = "hol";
	s2 = "adios";
	s3 = "ci";
	s4 = "au revoir";
	node1.content = s;
	node1.next = &node2;

	node2.content = s2;
	node2.next = &node3;

	node3.content = s3;
	node3.next = NULL;

	node4 = malloc(sizeof(t_list));
	if(!node4)
		return (NULL);
	node4->content = s4;
	node4->next = NULL;

	list = &node1;
	tmp = list;
	while (tmp)
	{
		printf("lst before: %s\n", tmp->content);
		tmp = tmp->next;
	}
	ft_lstadd_back(&list, node4);
	write(1, "\n", 1);
	tmp = list;
	while (tmp)
	{
		printf("lst after:  %s\n", tmp->content);
		tmp = tmp->next;
	}
	return (0);
}*/
