/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:48:54 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/27 16:48:54 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*lst;

	lst = *stack;
	while (lst->next != NULL)
	{
		if (lst->content > lst->next->content)
			return (1);
		else
			lst = lst->next;
	}
	return (0);
}

int	list_size(t_list **stack)
{
	t_list	*lst;
	int		len;

	lst = *stack;
	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void	reset_lst(t_list **stack)
{
	t_list	*lst_ptr;
	int		i;

	i = 0;
	lst_ptr = *stack;
	while ((*stack) != NULL)
	{
		(*stack)->index = i;
		(*stack)->target = NULL;
		(*stack)->cost = -1;
		(*stack) = (*stack)->next;
		i++;
	}
	*stack = lst_ptr;
}

t_list	*is_min(t_list **lst)
{
	t_list	*tmp;
	t_list	*min_ptr;
	int		min;

	tmp = *lst;
	min = (*lst)->content;
	min_ptr = *lst;
	while ((*lst) != NULL)
	{
		if ((*lst)->content < min)
		{
			min = (*lst)->content;
			min_ptr = *lst;
		}
		*lst = (*lst)->next;
	}
	*lst = tmp;
	return (min_ptr);
}
