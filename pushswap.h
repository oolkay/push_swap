/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oolkay <olkayomer@42.kocaeli>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 14:38:49 by oolkay            #+#    #+#             */
/*   Updated: 2023/03/16 17:17:48 by oolkay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_end(t_list **lst, int content);
void	ft_lstadd_head(t_list **lst, int content);
void	add_list(t_list **stackA, char **argv, int indx);
int		is_dup_arg(t_list *stackA);
int		is_sorted_arg(t_list *stackA);
void	sa(t_list **stackA, char c);
void	sb(t_list **stackB, char c);
void	ss(t_list **stackA, t_list **stackB, char c);
int		ft_atoi(const char *str);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstlast_second(t_list *lst);
void	rra(t_list **stackA, char c);
void	rrb(t_list **stackB, char c);
void	rrr(t_list **stackA, t_list**stackB, char c);
void	rr(t_list **stackA, t_list **stackB, char c);
void	ra(t_list **stackA, char c);
void	rb(t_list **stackB, char c);
void	pa(t_list **stackdest, t_list **stacksrc, char c);
void	pb(t_list **stackdest, t_list **stacksrc, char c);
void	init_stack_1(t_list **stackA, int argc, char **argv);
void	init_stack_2(t_list **stackA, char **argv);
int		ft_stacklen(t_list *stackA);
char	**ft_split(const char *s, char c);
int		mincontent(t_list *stackA);
int		maxcontent(t_list *stackA);
int		ft_stacksize(t_list *stackA);
void	ft_free(t_list **lst);
int		ft_find_index(t_list *stackdest, int pushnbr);
int		ft_find_place(t_list *stackdest, int pushnbr);
int		ft_find_place_in_a(t_list *stackdest, int pushnbr);
int		ft_find_move_amount(t_list *src, t_list *dst, char ch);
int		ft_case_rarb(t_list *src, t_list *dst, int pushnbr, char ch);
int		ft_case_rrarrb(t_list *src, t_list *dst, int pushnbr, char ch);
int		ft_case_rrarb(t_list *src, t_list *dst, int pushnbr, char ch);
int		ft_case_rarrb(t_list *src, t_list *dst, int pushnbr, char ch);
int		ft_apply_case_rarb(t_list **stackA, t_list **stackB,
			int pushnbr, char ch);
int		ft_apply_case_rrarrb(t_list **stackA, t_list **stackB,
			int pushnbr, char ch);
int		ft_apply_case_rrarb(t_list **stackA, t_list **stackB,
			int pushnbr, char ch);
int		ft_apply_case_rarrb(t_list **stackA, t_list **stackB,
			int pushnbr, char ch);
void	start_swap(t_list **stackA);
void	sort_a(t_list **stackA);
int		ft_min_amount(t_list *stacksrc, t_list *stackdest, char ch);
void	ft_error(void);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_putten(char *putline);
char	*get_main_line(char *putline);
char	*get_read(int fd, char *putline);
char	*get_next_line(int fd);

#	endif
