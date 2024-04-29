/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 18:19:00 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/03 18:19:00 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_cost(t_list *tmp, int lasta, int lastb)
{
	int	cost_target;

	cost_target = tmp->target->index;
	if (tmp->index > lastb / 2)
		tmp->cost = lastb - tmp->index;
	if (tmp->target->index > lasta / 2)
		cost_target = lasta - tmp->target->index;
	tmp->cost = tmp->cost + cost_target;
	return (tmp->cost);
}

void	get_target_cost(t_list **a, t_list **b)
{
	int		lasta;
	int		lastb;
	int		m_dis;
	int		t_dis;
	t_list	*tmp;

	tmp = *b;
	while (tmp != NULL)
	{
		lasta = ft_lstlast(*a)->index + 1;
		lastb = ft_lstlast(*b)->index + 1;
		tmp->target = find_target(*a, tmp);
		tmp->cost = tmp->index;
		m_dis = lastb - tmp->index;
		t_dis = lasta - tmp->target->index;
		if ((tmp->index > lastb / 2) && (tmp->target->index > lasta / 2))
			tmp->cost = max_cost(m_dis, t_dis);
		else if ((tmp->index < lastb / 2) && (tmp->target->index < lasta / 2))
			tmp->cost = max_cost(tmp->index, tmp->target->index);
		else
			tmp->cost = calc_cost(tmp, lasta, lastb);
		tmp = tmp->next;
	}
}

void	move_top(t_list **a, t_list **b, t_list *min, t_list *target)
{
	int	last_a;
	int	last_b;

	last_a = ft_lstlast(*a)->index + 1;
	last_b = ft_lstlast(*b)->index + 1;
	if (target->index > last_a / 2 && min->index > last_b / 2)
		move_top_rrr(a, b, min, target);
	else if (target->index < last_a / 2 && min->index < last_b / 2)
		move_top_rr(a, b, min, target);
	else
	{
		move_top_a(a, target);
		move_top_b(b, min);
	}
}

void	sort_final(t_list **a)
{
	t_list	*min;

	min = get_min_val(*a);
	move_top_a(a, min);
	reset_lst(a);
}

void	big_sort(t_list **a, t_list **b)
{
	t_list	*min;

	min = *b;
	while (*b != NULL)
	{
		get_target_cost(a, b);
		min = get_min(*b);
		move_top(a, b, min, min->target);
		pa(a, b);
		reset_lst(b);
		reset_lst(a);
	}
}
