/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 15:09:01 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/24 15:09:01 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s && s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			word++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (word);
}

char	*word_alloc(char const *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)ft_calloc((end - start + 1), 1);
	if (word)
	{
		while (start < end)
			word[i++] = s[start++];
		word[i] = '\0';
		return (word);
	}
	return (0);
}

char	**create_split(char const *s, char **split, int nwords, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (i < (int)ft_strlen(s) && j < nwords)
	{
		while (s[i] == c && i < (int)ft_strlen(s))
			i++;
		if (i == (int)ft_strlen(s))
			return (split);
		start = i;
		while (s[i] != c && i < (int)ft_strlen(s))
			i++;
		split[j] = word_alloc(s, start, i);
		start = i++;
		j++;
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		nwords;

	nwords = count_words(s, c);
	if (nwords == 0)
		return (NULL);
	split = (char **)ft_calloc((nwords + 1), (sizeof(char *)));
	if (split)
	{
		split = create_split(s, split, nwords, c);
		return (split);
	}
	return (0);
}
