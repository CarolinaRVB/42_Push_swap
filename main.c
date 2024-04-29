/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:44:39 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/23 10:44:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	args = join_args_split(ac, av);
	if (!args)
		return (1);
	ac = count_ar(args);
	if (check_arguments(args, ac) != 0)
	{
		free_argv(args);
		return (1);
	}
	init_args(&stack_a, args, ac);
	free_argv(args);
	start_sort(&stack_a, &stack_b, ac);
	return (0);
}
