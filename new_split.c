/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 18:26:56 by martalop          #+#    #+#             */
/*   Updated: 2024/04/25 18:12:05 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdio.h>

char	**free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static void	copy_words(char **array, char *str, char c)
{
	int	i;
	int	x;
	int	j;

	i = 0;
	x = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] == c) // el str[i] es importante para la ultima palabra cuando no hay 'c'
			i++;
		while (str[i] && str[i] != c)
		{
		//	printf("%c\n", str[i]);
			array[x][j] = str[i];
			i++;
			j++;
		}
		if (str[i] == c)
		{
			array[x][j++] = '/';
			array[x][j] = '\0';
		}
		x++;
	}
}

static int	create_string(char **array, char *str, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (str[i])
	{
		j = 0;
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			j++;
			i++;
		}
		if (str[i] == c || (!str[i] && str[i - 1] != c))
		{
			array[x] = malloc(sizeof(char) * (j + 2));
			if (!array[x])
				return (1);
			x++;
		}
	}
	array[x] = NULL;
	return (0);
}

static int	word_counter(char *str, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
		{
			i++;
		}
		word++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (word);
}

char	**split_add(char *str, char c)
{
	char	**array;
	int	word_count;

	array = NULL;
	word_count = word_counter(str, c);
	array = malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!create_string(array, str, c))
	{
		copy_words(array, str, c);
	}
	else
		array = free_array(array);
	return (array);
}

/*int	main(void)
{
	int	x;
	char	*str;
	char	**array;

	x = 0;
	str = "/bin/usr:/bin:";
	array = split_add(str, ':');
	while (array[x])
	{
		printf("%s\n", array[x]);
		free(array[x]);
		x++;
	}
	free(array);
	return (0);
}*/
