/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:42:46 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/17 19:42:46 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_rrr(t_list **a, t_list **b, t_list *min, t_list *target)
{
	int	m_dis;
	int	d_target;
	int	last_a;
	int	last_b;

	last_a = ft_lstlast(*a)->index + 1;
	last_b = ft_lstlast(*b)->index + 1;
	m_dis = last_b - min->index;
	d_target = last_a - target->index;
	if (m_dis > d_target)
		top_rrr_b(a, b, m_dis, d_target);
	else
		top_rrr_a(a, b, m_dis, d_target);
}

void	top_rrr_b(t_list **a, t_list **b, int m_dis, int t_dis)
{
	m_dis = m_dis - t_dis;
	while (t_dis > 0)
	{
		rrr(a, b);
		t_dis--;
	}
	while (m_dis > 0)
	{
		rrb(b);
		write(1, "rrb\n", 4);
		m_dis--;
	}
}

void	top_rrr_a(t_list **a, t_list **b, int m_dis, int t_dis)
{
	t_dis = t_dis - m_dis;
	while (m_dis > 0)
	{
		rrr(a, b);
		m_dis--;
	}
	while (t_dis > 0)
	{
		rra(a);
		write(1, "rra\n", 4);
		t_dis--;
	}
}

void	move_top_b(t_list **b, t_list *min)
{
	int	last;

	last = ft_lstlast(*b)->index + 1;
	if (min->index > last / 2)
	{
		while (last - min->index > 0)
		{
			rrb(b);
			write(1, "rrb\n", 4);
			min->index = min->index + 1;
		}
	}
	else
	{
		while (min->index > 0)
		{
			rb(b);
			write(1, "rb\n", 3);
			min->index = min->index - 1;
		}
	}
}

void	move_top_a(t_list **a, t_list *target)
{
	int	last;

	last = ft_lstlast(*a)->index + 1;
	if (target->index > last / 2)
	{
		while (last - target->index > 0)
		{
			rra(a);
			write(1, "rra\n", 4);
			target->index = target->index + 1;
		}
	}
	else
	{
		while (target->index > 0)
		{
			ra(a);
			write(1, "ra\n", 3);
			target->index = target->index - 1;
		}
	}
}
