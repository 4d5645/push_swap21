/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdara <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:04:33 by gdara             #+#    #+#             */
/*   Updated: 2022/02/02 20:04:33 by gdara            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(int content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	check_digits(int argc, char **argv);
void	check_ints(int argc, char **argv);
void	check_duplicates(int argc, char **argv);
t_list	**initialize_stack(t_list **stack_a, int argc, char **argv);
void	write_and_close(void);
void	swap(t_list **stack);
void	push(t_list **stack_dest, t_list **stack_src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack);
void	bubble_sort(int *a, int n);
void	swap_bubble(int *a, int *b);
void	run_swap(t_list **stack_a, t_list **stack_b, char flag);
void	run_push(t_list **stack_a, t_list **stack_b, char flag);
void	run_rotate(t_list **stack_a, t_list **stack_b, char flag);
void	run_reverse_rotate(t_list **stack_a, t_list **stack_b, char flag);
void	initialize_indicies(t_list **stack, int *array, int count);
void	sort_fiveorless(t_list **stack_a, t_list **stack_b, int count);
int		*ft_fill_array(t_list **stack, int n);
void	sort_a_lot(t_list **stack_a, t_list **stack_b, int count);
int		a_is_sorted(t_list **stack);
void	clear_and_close(t_list **stack_a, t_list **stack_b, char flag);

#endif