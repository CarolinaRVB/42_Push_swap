/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:35:24 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/02 15:35:24 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	int		i;
	int		j;
	char	*sjoin;

	if (!s1 || !s2)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	j = 0;
	i = 0;
	sjoin = (char *)ft_calloc((s1len + s2len + 1), 1);
	if (sjoin)
	{
		while (s1[i] != '\0')
		{
			sjoin[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
			sjoin[i++] = s2[j++];
		return (sjoin);
	}
	return (NULL);
}

char	*join_args(int ac, char *av[])
{
	int		i;
	char	*str;
	char	*tmp;
	char	*space;
	int		flag;

	str = av[1];
	i = 2;
	flag = 0;
	space = " ";
	while (i < ac)
	{
		tmp = ft_strjoin(str, space);
		if (flag != 0)
			free(str);
		flag = 1;
		str = tmp;
		tmp = ft_strjoin(str, av[i]);
		free(str);
		str = tmp;
		i++;
	}
	return (str);
}

char	**join_args_split(int ac, char *av[])
{
	char	**arg;
	char	*str;

	str = join_args(ac, av);
	arg = ft_split(str, ' ');
	if (!arg && ft_strlen(str))
		error_exit();
	if (!arg)
		return (NULL);
	if (ac > 2)
		free(str);
	if (arg[0] == NULL)
		return (NULL);
	return (arg);
}

int	count_ar(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}
