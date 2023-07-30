/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hstein <hstein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 19:31:32 by hstein            #+#    #+#             */
/*   Updated: 2023/07/25 19:31:32 by hstein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

static size_t	countwords(char const *s, char c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	if (c == '\0')
		return (1);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		while (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	wordlen(char const *s, char c, int i)
{
	size_t	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**sub(char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	char	**res;
	size_t	len;

	i = 0;
	j = 0;
	res = (char **)malloc(sizeof(char *) * (count + 1));
	if (res == NULL)
		return (0);
	while (j < count && (size_t)i < ft_strlen(s))
	{
		if (s[i] == c)
			i++;
		else
		{
			len = wordlen(s, c, i);
			res[j] = ft_substr(s, (unsigned int) i, len);
			if (!res[j++])
				return (ft_free(res));
			i += len;
		}
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	count;

	if (s == NULL)
		return (0);
	count = countwords(s, c);
	res = sub(s, c, count);
	if (!res)
		return (0);
	return (res);
}
/*
int main()
{
    char    test[] = "0000000abcde000000blagiu00";
    char    del = '\0';
    char    **res;
    int     i = 0;

	res = ft_split(test, del);
	while (i < 1)
		printf("%s\n", res[i++]);
    
    free(res);
}*/
