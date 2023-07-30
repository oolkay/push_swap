/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushb_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:58:46 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 17:18:11 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_3(t_list **stacka)
{
	if ((*stacka)->content == mincontent(*stacka))
	{
		sa(stacka, 'm');
		ra(stacka, 'm');
	}
	else if ((*stacka)->content == maxcontent(*stacka)
		&& (*stacka)->next->content == mincontent(*stacka))
		ra(stacka, 'm');
	else if ((*stacka)->content == maxcontent(*stacka)
		&& (*stacka)->next->content != mincontent(*stacka))
	{
		sa(stacka, 'm');
		rra(stacka, 'm');
	}
	else if ((*stacka)->content != mincontent(*stacka)
		&& ft_lstlast(*stacka)->content == maxcontent(*stacka))
		sa(stacka, 'm');
	else if ((*stacka)->content != mincontent(*stacka)
		&& ft_lstlast(*stacka)->content != maxcontent(*stacka))
		rra(stacka, 'm');
}

void	sort_b_and_push_a(t_list **stacka, t_list **stackb)
{
	int		i;
	t_list	*tmp;

	while (ft_stacksize(*stackb) > 0)
	{
		tmp = *stackb;
		i = ft_min_amount(*stackb, *stacka, 'b');
		while (i != -1)
		{
			if (i == ft_case_rarb(*stackb, *stacka, tmp->content, 'b'))
				i = ft_apply_case_rarb(stacka, stackb, tmp->content, 'b');
			else if (i == ft_case_rrarrb(*stackb, *stacka, tmp->content, 'b'))
				i = ft_apply_case_rrarrb(stacka, stackb, tmp->content, 'b');
			else if (i == ft_case_rrarb(*stackb, *stacka, tmp->content, 'b'))
				i = ft_apply_case_rrarb(stacka, stackb, tmp->content, 'b');
			else if (i == ft_case_rarrb(*stackb, *stacka, tmp->content, 'b'))
				i = ft_apply_case_rarrb(stacka, stackb, tmp->content, 'b');
			tmp = tmp->next;
		}
	}
}

void	pushb_3(t_list **stacka, t_list **stackb)
{
	int		i;
	t_list	*tmp;

	while (ft_stacksize(*stacka) > 3 && is_sorted_arg(*stacka) == 0 && tmp)
	{
		tmp = *stacka;
		i = ft_min_amount(*stacka, *stackb, 'a');
		while (i != -1)
		{
			if (i == ft_case_rarb(*stacka, *stackb, tmp->content, 'a'))
				i = ft_apply_case_rarb(stacka, stackb, tmp->content, 'a');
			else if (i == ft_case_rrarrb(*stacka, *stackb, tmp->content, 'a'))
				i = ft_apply_case_rrarrb(stacka, stackb, tmp->content, 'a');
			else if (i == ft_case_rrarb(*stacka, *stackb, tmp->content, 'a'))
				i = ft_apply_case_rrarb(stacka, stackb, tmp->content, 'a');
			else if (i == ft_case_rarrb(*stacka, *stackb, tmp->content, 'a'))
				i = ft_apply_case_rarrb(stacka, stackb, tmp->content, 'a');
			else
				tmp = tmp->next;
		}
	}
	if (is_sorted_arg(*stacka) == 0)
		sort_3(stacka);
}

void	sort_a(t_list **stacka)
{
	int	min;
	int	size;
	int	index;

	min = mincontent(*stacka);
	size = ft_stacksize(*stacka);
	index = ft_find_index(*stacka, min);
	if (index < size / 2)
	{
		while (is_sorted_arg(*stacka) == 0)
			ra(stacka, 'm');
	}
	else
	{
		while (is_sorted_arg(*stacka) == 0)
			rra(stacka, 'm');
	}
}

void	start_swap(t_list **stacka)
{
	t_list	*stackb;

	stackb = NULL;
	if (ft_stacksize(*stacka) == 3)
	{
		sort_3(stacka);
		return ;
	}
	else if (ft_stacksize(*stacka) == 2)
	{
		sa(stacka, 'm');
		return ;
	}
	else if (ft_stacksize(*stacka) == 1)
		return ;
	else if (ft_stacksize(*stacka) < 1)
		ft_error();
	if (ft_stacksize(*stacka) > 3 && is_sorted_arg(*stacka) == 0)
		pb(&stackb, stacka, 'm');
	if (ft_stacksize(*stacka) > 3 && is_sorted_arg(*stacka) == 0)
		pb(&stackb, stacka, 'm');
	pushb_3(stacka, &stackb);
	sort_b_and_push_a(stacka, &stackb);
	if (is_sorted_arg(*stacka) == 0)
		sort_a(stacka);
}
