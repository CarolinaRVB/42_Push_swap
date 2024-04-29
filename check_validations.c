/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 19:24:10 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/06 16:26:40 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_exit(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	valid_av(char **av, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (is_digit(av[i]) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	valid_int(char **av, int size)
{
	int			i;
	long int	nb;

	i = 0;
	while (i < size)
	{
		if (ft_strlen(av[i]) > 11)
			return (1);
		nb = ft_atol(av[i]);
		if (nb > INT_MAX)
			return (1);
		if (nb < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_dup(char **s, int i, int j)
{
	while (i < j)
	{
		if (ft_atoi(s[i]) == ft_atoi(s[j]))
			return (1);
		i++;
	}
	return (0);
}

int	no_dup(char **av, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size && j < size)
	{
		i = 0;
		if (check_dup(av, i, j) != 0)
			return (1);
		j++;
	}
	return (0);
}
