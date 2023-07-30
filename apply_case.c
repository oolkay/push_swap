/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:00:03 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:06:19 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_apply_case_rarb(t_list **stackA, t_list **stackB, int pushnbr, char ch)
{
	if (ch == 'a')
	{
		while ((*stackA)->content != pushnbr
			&& 0 < ft_find_place(*stackB, pushnbr))
			rr(stackA, stackB, 'm');
		while ((*stackA)->content != pushnbr)
			ra(stackA, 'm');
		while (ft_find_place(*stackB, pushnbr) > 0)
			rb(stackB, 'm');
		pb(stackB, stackA, 'm');
	}
	else
	{
		while ((*stackB)->content != pushnbr
			&& 0 < ft_find_place_in_a(*stackA, pushnbr))
			rr(stackA, stackB, 'm');
		while ((*stackB)->content != pushnbr)
			rb(stackB, 'm');
		while (ft_find_place_in_a(*stackA, pushnbr) > 0)
			ra(stackA, 'm');
		pa(stackA, stackB, 'm');
	}
	return (-1);
}

int	ft_apply_case_rrarrb(t_list **stackA, t_list **stackB, int pushnbr, char ch)
{
	if (ch == 'a')
	{
		while ((*stackA)->content != pushnbr
			&& ft_find_place(*stackB, pushnbr) > 0)
			rrr(stackA, stackB, 'm');
		while ((*stackA)->content != pushnbr)
			rra(stackA, 'm');
		while (ft_find_place(*stackB, pushnbr) > 0)
			rrb(stackB, 'm');
		pb(stackB, stackA, 'm');
	}
	else
	{
		while ((*stackB)->content != pushnbr
			&& ft_find_place_in_a(*stackA, pushnbr) > 0)
			rrr(stackA, stackB, 'm');
		while ((*stackB)->content != pushnbr)
			rrb(stackB, 'm');
		while (ft_find_place_in_a(*stackA, pushnbr) > 0)
			rra(stackA, 'm');
		pa(stackA, stackB, 'm');
	}
	return (-1);
}

int	ft_apply_case_rrarb(t_list **stackA, t_list **stackB, int pushnbr, char ch)
{
	if (ch == 'a')
	{
		while ((*stackA)->content != pushnbr)
			rra(stackA, 'm');
		while (ft_find_place(*stackB, pushnbr) > 0)
			rb(stackB, 'm');
		pb(stackB, stackA, 'm');
	}
	else
	{
		while ((*stackB)->content != mincontent(*stackB))
			rb(stackB, 'm');
		while (ft_find_place_in_a(*stackA, pushnbr) > 0)
			rra(stackA, 'm');
		pa(stackA, stackB, 'm');
	}
	return (-1);
}

int	ft_apply_case_rarrb(t_list **stackA, t_list **stackB, int pushnbr, char ch)
{
	if (ch == 'a')
	{
		while ((*stackA)->content != pushnbr)
			ra(stackA, 'm');
		while (ft_find_place(*stackB, pushnbr) > 0)
			rrb(stackB, 'm');
		pb(stackB, stackA, 'm');
	}
	else
	{
		while ((*stackB)->content != pushnbr)
			rrb(stackB, 'm');
		while (ft_find_place_in_a(*stackA, pushnbr) > 0)
			ra(stackA, 'm');
		pa(stackA, stackB, 'm');
	}
	return (-1);
}
