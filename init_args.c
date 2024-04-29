/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:26:42 by crebelo-          #+#    #+#             */
/*   Updated: 2023/09/26 12:26:42 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	free_list(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	node = *stack;
	while (node)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
}

void	ft_add_node(t_list **lst, char *str, int index)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node)
	{
		node->content = ft_atoi(str);
		node->index = index;
		node->cost = 0;
		node->target = NULL;
		node->next = NULL;
		ft_lstadd_back(lst, node);
	}
	else
	{
		free_list(lst);
		error_exit();
	}
}

void	init_args(t_list **stack, char **av, int ac)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < ac)
	{
		ft_add_node(stack, av[i], j);
		i++;
		j++;
	}
}
