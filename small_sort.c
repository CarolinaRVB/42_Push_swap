/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:55:15 by crebelo-          #+#    #+#             */
/*   Updated: 2023/11/01 13:55:15 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	five_sort(t_list **a, t_list **b, t_list *min)
{
	if (min->index == 1)
		sa(a);
	else if (min->index == 2)
	{
		ra(a);
		ra(a);
		write(1, "ra\nra\n", 6);
	}
	else if (min->index == 3)
	{
		rra(a);
		rra(a);
		write(1, "rra\nrra\n", 8);
	}
	else if (min->index == 4)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	pb(a, b);
	write(1, "pb\n", 3);
	reset_lst(a);
}

void	four_sort(t_list **a, t_list **b)
{
	t_list	*min;
	int		min_index;

	min = is_min(a);
	min_index = min->index;
	if (min_index == 1)
	{
		sa(a);
	}
	else if (min_index == 2)
	{
		rra(a);
		rra(a);
		write(1, "rra\nrra\n", 8);
	}
	else if (min_index == 3)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	pb(a, b);
	write(1, "pb\n", 3);
	reset_lst(a);
}

void	three_sort(t_list **a)
{
	t_list	*min;

	min = is_min(a);
	if (min->index == 0)
	{
		if ((*a)->next->content > (*a)->next->next->content)
		{
			ra(a);
			write(1, "ra\n", 3);
			sa(a);
			rra(a);
			write(1, "rra\n", 4);
		}
	}
	else if (min->index == 1)
	{
		if ((*a)->content > (*a)->next->next->content)
		{
			ra(a);
			write(1, "ra\n", 3);
		}
		else
			sa(a);
	}
}

void	three_sort_extra(t_list **a)
{
	if ((*a)->content > (*a)->next->content)
	{
		sa(a);
		rra(a);
		write(1, "rra\n", 4);
	}
	else
	{
		rra(a);
		write(1, "rra\n", 4);
	}
}

void	small_sort(t_list **a, t_list **b, int size)
{
	t_list	*min;

	min = *a;
	if (ft_lstlast(*a)->index == 4)
	{
		min = is_min(a);
		five_sort(a, b, min);
	}
	if (ft_lstlast(*a)->index == 3)
		four_sort(a, b);
	min = is_min(a);
	if ((ft_lstlast(*a)->index == 2 && min->index != 2))
		three_sort(a);
	else if (min->index == 2)
		three_sort_extra(a);
	if (ft_lstlast(*a)->index == 1)
		if ((*a)->content > (*a)->next->content)
			sa(a);
	while (size - 3 > 0)
	{
		pa(a, b);
		size--;
	}
}
