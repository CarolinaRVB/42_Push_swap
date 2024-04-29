/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_list_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:36:21 by crebelo-          #+#    #+#             */
/*   Updated: 2023/10/16 17:36:21 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **lst)
{
	t_list	*lst_ptr;
	t_list	*last;
	t_list	*tmp;

	tmp = (*lst)->next;
	lst_ptr = *lst;
	last = ft_lstlast(lst_ptr);
	last->next = lst_ptr;
	lst_ptr->next = NULL;
	*lst = tmp;
}

void	sb(t_list **lst)
{
	t_list	*tmp;
	int		size;

	size = list_size(lst);
	if (size < 2)
		return ;
	tmp = (*lst)->next;
	(*lst)->next = tmp->next;
	tmp->next = *lst;
	*lst = tmp;
	write(1, "sb\n", 3);
}

void	rrb(t_list **lst)
{
	t_list	*last;
	t_list	*before_last;

	before_last = *lst;
	last = ft_lstlast(*lst);
	while (before_last->next->next != NULL)
		before_last = before_last->next;
	last->next = *lst;
	before_last->next = NULL;
	*lst = last;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*lst_ptr;

	lst_ptr = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, lst_ptr);
	reset_lst(b);
}
