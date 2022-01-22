#include "../inc/pushswap.h"

int	check_ifsorted(t_list	**stack)
{
	t_list	*elem;
	int		min;
	int		count;

	count = -1;
	elem = *stack;
	min = elem->content;
	while (elem)
	{
		if (min > elem->content)
			return (count);
		count++;
		min = elem->content;
		elem = elem->next;
	}
	return (0);
}

void    sort_three(t_list **stack)
{
    t_list	*second;
	t_list	*third;

	second = (*stack)->next;
	third = second->next;
	if ((second->content > third->content) || ((*stack)->content < third->content))
		swap(stack);
	if ((*stack)->content > second->content && (*stack)->content < third->content)
	 	return (swap(stack));
	if ((*stack)->content > second->content && (*stack)->content > third->content)
	 	return (rotate(stack));
	return (reverse_rotate(stack));
}