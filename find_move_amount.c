/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_move_amount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:55:12 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 14:17:49 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_case_rarb(t_list *src, t_list *dst, int pushnbr, char ch)
{
	int	i;

	i = ft_find_place(dst, pushnbr);
	if (ch == 'a')
	{
		i = ft_find_place(dst, pushnbr);
		if (ft_find_index(src, pushnbr) > i)
			i = ft_find_index(src, pushnbr);
	}
	else
	{
		i = ft_find_place_in_a(dst, pushnbr);
		if (ft_find_index(src, pushnbr) > i)
			i = ft_find_index(src, pushnbr);
	}
	return (i);
}

int	ft_case_rrarrb(t_list *src, t_list *dst, int pushnbr, char ch)
{
	int	i;

	i = 0;
	if (ch == 'a')
	{
		if (ft_find_place(dst, pushnbr))
			i = ft_stacksize(dst) - ft_find_place(dst, pushnbr);
		if (ft_stacksize(src) - ft_find_index(src, pushnbr) > i
			&& ft_find_index(src, pushnbr) != 0)
			i = ft_stacksize(src) - ft_find_index(src, pushnbr);
	}
	else
	{
		if (ft_find_place_in_a(dst, pushnbr))
			i = ft_stacksize(dst) - ft_find_place_in_a(dst, pushnbr);
		if (ft_stacksize(src) - ft_find_index(src, pushnbr) > i
			&& ft_find_index(src, pushnbr) != 0)
			i = ft_stacksize(src) - ft_find_index(src, pushnbr);
	}
	return (i);
}

int	ft_case_rrarb(t_list *src, t_list *dst, int pushnbr, char ch)
{
	int	i;

	i = 0;
	if (ch == 'a')
	{
		if (ft_find_index(src, pushnbr))
			i = ft_stacksize(src) - ft_find_index(src, pushnbr);
		i += ft_find_place(dst, pushnbr);
	}
	else
	{
		if (ft_find_place_in_a(dst, pushnbr))
			i = ft_stacksize(dst) - ft_find_place_in_a(dst, pushnbr);
		i += ft_find_index(src, pushnbr);
	}
	return (i);
}

int	ft_case_rarrb(t_list *src, t_list *dst, int pushnbr, char ch)
{
	int	i;

	i = 0;
	if (ch == 'a')
	{
		if (ft_find_place(dst, pushnbr))
			i = ft_stacksize(dst) - ft_find_place(dst, pushnbr);
		i += ft_find_index(src, pushnbr);
	}
	else
	{
		if (ft_find_index(src, pushnbr))
			i = ft_stacksize(src) - ft_find_index(src, pushnbr);
		i += ft_find_place_in_a(dst, pushnbr);
	}
	return (i);
}

int	ft_find_move_amount(t_list *src, t_list *dst, char ch)
{
	int		i;
	t_list	*tmp;

	tmp = src;
	i = ft_case_rrarrb(src, dst, src->content, ch);
	while (tmp)
	{
		if (i > ft_case_rarb(src, dst, tmp->content, ch))
			i = ft_case_rarb(src, dst, tmp->content, ch);
		if (i > ft_case_rrarrb(src, dst, tmp->content, ch))
			i = ft_case_rrarrb(src, dst, tmp->content, ch);
		if (i > ft_case_rarrb(src, dst, tmp->content, ch))
			i = ft_case_rarrb(src, dst, tmp->content, ch);
		if (i > ft_case_rrarb(src, dst, tmp->content, ch))
			i = ft_case_rrarb(src, dst, tmp->content, ch);
		tmp = tmp->next;
	}
	return (i);
}
