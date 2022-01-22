#include "../inc/pushswap.h"

void    write_and_close()
{
    ft_putstr_fd("Error\n", 1);
    exit(1);
}
static int	*ft_array(t_list **stack, int n)
{
	int		*a;
	t_list	*elem;
	int		i;

	elem = *stack;
	i = -1;
	a = (int *)malloc(sizeof(int) * n);
	if (!a)
		return (0);
	while (n--)
	{
		a[++i] = elem->content;
		elem = elem->next;
	}
	return (a);
}

static int	*sort_array(t_list **stack, int n)
{
	int	*a;
	int	i;
	int	j;

	a = ft_array(stack, n);
	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n - i - 1)
		{
			if (a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
	}
	return (a);
}

static int	change_content(t_list **stack, int *sarray, int len)
{
	t_list	*elem;
	int		i;

	elem = *stack;
	while (elem)
	{
		i = -1;
		while (++i < len)
		{
			if (sarray[i] == elem->content)
				break ;
		}
		if (i == len)
			return (0);
		elem->content = i;
		
		elem = elem->next;
	}
	return (1);
}