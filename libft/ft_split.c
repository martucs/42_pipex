/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:54:56 by martalop          #+#    #+#             */
/*   Updated: 2024/04/25 13:07:24 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

static int	ft_word_counter(const char *s, char c)
{
	int	ctr;
	int	i;
	int	word;

	i = 0;
	word = 0;
	ctr = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			ctr++;
		else if (s[i] == c && ctr > 0)
		{
			ctr = 0;
			word++;
		}
		i++;
	}
	if (ctr > 0)
		word++;
	return (word);
}

static char	**ft_new_strings(char **array, char const *s, char c)
{
	int	i;
	int	ctr;
	int	x;

	i = 0;
	ctr = 0;
	x = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			ctr++;
		if ((s[i] == c && ctr > 0) || (s[i] != c && s[i + 1] == '\0'))
		{
			array[x] = malloc(sizeof(char) * (ctr + 1));
			if (!array[x])
				return (NULL);
			ctr = 0;
			x++;
		}
		i++;
	}
	return (array);
}

static char	**ft_copy(char **array, char const *s, char c)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			array[x][y++] = s[i];
		if (s[i] != c && s[i + 1] == '\0')
			array[x][y] = '\0';
		else if (s[i] == c && i > 0 && s[i - 1] != c)
		{
			array[x][y] = '\0';
			x++;
			y = 0;
		}
		i++;
	}
	return (array);
}

static char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		wordcount;

	if (!s)
	{
		array = malloc(sizeof(char) * 1);
		if (!array)
			return (NULL);
		*array = NULL;
		return (array);
	}
	wordcount = ft_word_counter(s, c);
	array = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!array)
		return (NULL);
	if (ft_new_strings(array, s, c))
	{
		ft_copy(array, s, c);
		array[wordcount] = NULL;
	}
	else
		array = ft_free(array);
	return (array);
}

/*#include <stdio.h>
int	main(void)
{
	char s[] = "hola   como estas";
	char c = ' ';
	int i = 0;
	//printf("%d\n", ft_word_counter(s, c));
	char **res;
	
	res = ft_split(s, c);
	while (res[i])
	{
		printf("%s\n",res[i]);
		free(res[i]);
		i++;
	}
	free(res);
}*/

/*int	main(void)
{
	int	x;
	char	*str;
	char	**array;

	x = 0;
	str = "/bin/usr:/bin:";
	array = ft_split(str, ':');
	while (array[x])
	{
		printf("%s\n", array[x]);
		free(array[x]);
		x++;
	}
	free(array);
	return (0);
}*/
