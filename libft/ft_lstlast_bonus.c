/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:57:19 by martalop          #+#    #+#             */
/*   Updated: 2024/03/28 17:24:30 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

/*int	main()
{
	t_list	*list;
	t_list	node1;
	t_list	node2;
	t_list	node3;
	t_list	*res;
	char	*s;
	char	*s2;
	char	*s3;

	s = "hol";
	s2 = "adios";
	s3 = "ci";
	node1.content = s;
	node1.next = &node2;

	node2.content = s2;
	node2.next = &node3;

	node3.content = s3;
	node3.next = NULL;

	list = &node1;
	printf("lst before: %s\n", list->content);
	res = ft_lstlast(list);
	printf("lst after:  %s\n", list->content);
	printf("%s\n", res->content);
	printf("%p\n", res->next);
	return (0);
}*/	
