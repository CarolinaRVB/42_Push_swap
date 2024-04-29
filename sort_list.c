/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:25:39 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/27 17:25:39 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_list(t_list **a, t_list **b, int size)
{
	int	max;

	max = get_max(*a)->content;
	if (size < 6)
		small_sort(a, b, size);
	else
	{
		while (ft_lstlast(*a)->index > 4)
		{
			if ((*a)->content == max)
			{
				ra(a);
				write(1, "ra\n", 3);
			}
			pb(a, b);
			reset_lst(a);
			write(1, "pb\n", 3);
		}
		small_sort(a, b, 5);
		reset_lst(b);
		big_sort(a, b);
		sort_final(a);
	}
}
