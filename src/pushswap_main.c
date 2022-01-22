#include "../inc/pushswap.h"
#include <stdio.h>

int	a_is_sorted(t_list **stack)
{
	t_list	*current;
	t_list	*check;

	current = *stack;
	if (current == 0)
		return (0);
	while (current != 0)
	{
		check = current->next;
		while (check)
		{
			if (current->content > check->content)
				return (0);
			check = check->next;
		}
		current = current->next;
	}
	return (1);
}

void sort(t_list **stack_a, int count)
{
	if (count == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap(stack_a);
	}
	if (count == 3)
		sort_three(stack_a);
}

void	print_stack(t_list *stack)
{
	t_list *end = stack;
	if (end != 0)
	{
		while (end)
		{
			printf("%d ", end->content);
			end = end->next;
		}
		printf("NULL\n");
	}
}

int main(int argc, char **argv)
{
    t_list	**stack_a;
    t_list	**stack_b;

	stack_a = NULL;
	if (argc < 2)
		exit(1);
	stack_a = initialize_stack(stack_a, argc, argv);
	if (argc < 3)
	{
		ft_lstclear(stack_a, NULL);
		exit(1);
	}
	if (a_is_sorted(stack_a) == 1)
	{
		ft_lstclear(stack_a, NULL);
		exit(1);
	}
	stack_b = (t_list  **)malloc(sizeof(t_list *) * (argc - 1));
	if (!stack_b)
	{
		ft_lstclear(stack_a, NULL);
		ft_lstclear(stack_b, NULL);
		exit(1);
	}
	*stack_b = NULL;
	sort(stack_a, argc - 1);
	print_stack(*stack_a);
}