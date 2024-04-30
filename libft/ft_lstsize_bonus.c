/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:38:34 by martalop          #+#    #+#             */
/*   Updated: 2024/03/28 16:55:32 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->next != NULL)
		{
			lst = lst->next;
			i++;
		}
		else
		{
			i++;
			break ;
		}
	}
	return (i);
}

/*int	main()
{
	t_list	*list;
	t_list	node1;
	t_list	node2;
	t_list	node3;
	int	res;
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
	res = ft_lstsize(list);
	printf("%d\n", res);
	return (0);
}	*/
