#include "../inc/pushswap.h"

void	swap(t_list **stack)
{
	int	tmp;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->content;
		(*stack)->content = (*stack)->next->content;
		(*stack)->next->content = tmp;
	}
}



void	push(t_list **stack_dest, t_list **stack_src)
{
	t_list	*tmp;

	if (stack_src && (*stack_src))
	{
		tmp = *stack_src;
		if (!(*stack_src)->next)
			*stack_src = NULL;
		else
			*stack_src = (*stack_src)->next;
		ft_lstadd_front(stack_dest, tmp);
	}
}

void	rotate(t_list **stack)
{
	t_list	*start;

	if (*stack != 0)
	{
		start = *stack;
		while ((*stack)->next)
			(*stack) = (*stack)->next;
		start = start->next;
		start->next = NULL;
		(*stack)->next = start;
	}
	else
		return ;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*start;
	t_list	*before_end;
	t_list	*end;

	if (*stack && (*stack)->next)
	{
		start = *stack;
		while ((*stack)->next)
		{
			before_end = *stack;
			(*stack) = (*stack)->next;
		}
		end = *stack;
		before_end->next = NULL;
		end->next = start;
		*stack = end;
	}
}