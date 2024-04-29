/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:01:26 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/04 15:01:26 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_target(t_list *a, t_list *b)
{
	t_list	*target;
	t_list	*tmpa;

	tmpa = a;
	target = NULL;
	while (tmpa && tmpa->next != NULL)
	{
		while (target == NULL && tmpa != NULL && (tmpa->content < b->content))
			tmpa = tmpa->next;
		if (tmpa == NULL)
			return (tmpa);
		if (target == NULL)
			target = tmpa;
		if (tmpa && tmpa->next != NULL && (tmpa->next->content > b->content)
			&& (tmpa->next->content < target->content))
			target = tmpa->next;
		tmpa = tmpa->next;
	}
	return (target);
}

t_list	*get_min(t_list *b)
{
	t_list	*tmp1;
	t_list	*min;

	min = b;
	tmp1 = b->next;
	while (tmp1)
	{
		if (tmp1->cost < min->cost)
			min = tmp1;
		tmp1 = tmp1->next;
	}
	return (min);
}

t_list	*get_min_val(t_list *lst)
{
	t_list	*tmp1;
	t_list	*min;

	min = lst;
	tmp1 = lst->next;
	while (tmp1)
	{
		if (tmp1->content < min->content)
			min = tmp1;
		tmp1 = tmp1->next;
	}
	return (min);
}

t_list	*get_max(t_list *lst)
{
	t_list	*tmp1;
	t_list	*max;

	max = lst;
	tmp1 = lst->next;
	while (tmp1)
	{
		if (tmp1->content > max->content)
			max = tmp1;
		tmp1 = tmp1->next;
	}
	return (max);
}
