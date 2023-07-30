/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:59:59 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 17:56:28 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_checker_rrx(t_list **stacka, t_list **stackb, char *line)
{
	if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a' && line[3] == '\n')
		rra(stacka, 'b');
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'b' && line[3] == '\n')
		rrb(stackb, 'b');
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(stacka, stackb, 'b');
	else if (line[0] == 'r' && line[1] == 'r'
		&& line[2] == 'r' && line[3] == '\n')
		rrr(stacka, stackb, 'b');
	else
		ft_error();
}

void	ft_checker_sx(t_list **stacka, t_list **stackb, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		sa(stacka, 'b');
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		sb(stackb, 'b');
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ss(stacka, stackb, 'b');
	else
		ft_error();
}

int	ft_checker(t_list **stacka, t_list **stackb)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (line[0] == 's')
			ft_checker_sx(stacka, stackb, line);
		else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
			pa(stacka, stackb, 'b');
		else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
			pb(stackb, stacka, 'b');
		else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
			rb(stackb, 'b');
		else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
			ra(stacka, 'b');
		else if (line[0] == 'r' && line[1] == 'r')
			ft_checker_rrx(stacka, stackb, line);
		else
			ft_error();
		line = get_next_line(0);
	}
	free(line);
	if (is_sorted_arg(*stacka) == 0 || (*stackb))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;

	if (argc <= 1)
		return (0);
	init_stack_1(&stacka, argc, argv);
	if (!stacka || is_dup_arg(stacka) == 0)
	{
		ft_free(&stacka);
		ft_error();
	}
	if (ft_checker(&stacka, &stackb) == 0)
		write (1, "KO\n", 3);
	if (ft_checker(&stacka, &stackb) == 1)
		write (1, "OK\n", 3);
	ft_free(&stackb);
	ft_free(&stacka);
}
