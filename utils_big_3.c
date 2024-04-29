/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:44:18 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/17 19:44:18 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_top_rr(t_list **a, t_list **b, t_list *min, t_list *target)
{
	int	m_dis;
	int	d_target;

	m_dis = min->index;
	d_target = target->index;
	if (m_dis > d_target)
		top_rr_b(a, b, m_dis, d_target);
	else
		top_rr_a(a, b, m_dis, d_target);
}

void	top_rr_b(t_list **a, t_list **b, int m_dis, int t_dis)
{
	m_dis = m_dis - t_dis;
	while (t_dis > 0)
	{
		rr(a, b);
		t_dis--;
	}
	while (m_dis > 0)
	{
		rb(b);
		write(1, "rb\n", 3);
		m_dis--;
	}
}

void	top_rr_a(t_list **a, t_list **b, int m_dis, int t_dis)
{
	t_dis = t_dis - m_dis;
	while (m_dis > 0)
	{
		rr(a, b);
		m_dis--;
	}
	while (t_dis > 0)
	{
		ra(a);
		write(1, "ra\n", 3);
		t_dis--;
	}
}

int	max_cost(int a, int b)
{
	int	max;

	max = 0;
	if (a > b)
		max = a;
	else
		max = b;
	return (max);
}
