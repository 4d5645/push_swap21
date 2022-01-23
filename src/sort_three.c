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
    t_list	*third;
	t_list	*second;

    second = (*stack)->next;
	third = second->next;
    if (third->content > (*stack)->content && second->content < (*stack)->content)
        swap(stack);
    else if (third->content < second->content && (*stack)->content > second->content)
    {
        swap(stack);
        reverse_rotate(stack);
    }
    else if (third->content < (*stack)->content && second->content < third->content)
        rotate(stack);
    else if (second->content > third->content && (*stack)->content < third->content)
    {
        swap(stack);
        rotate(stack);
    }
    else if ((*stack)->content < second->content && third->content < (*stack)->content)
        reverse_rotate(stack);
}