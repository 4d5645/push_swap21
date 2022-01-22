#include "../inc/pushswap.h"

void	check_argvs(int argc, char **argv)
{
	int	i;
	int	j;
	int	value;

	i = 1;
	j = 0;
	while (i < argc)
	{
		value = ft_atoi(argv[i]);
		if (value > INT32_MAX || value < INT32_MIN)
			write_and_close();
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				write_and_close();
			j++;
		}
		i++;
	}
}

void	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;
	int	n;

	j = 1;
	while (j < argc - 1)
	{
		i = j + 1;
		while (i <= argc - 1)
		{
			n = 0;
			while (argv[i][n] != 0 && argv[j][n] != 0)
			{
				if (argv[i][n] != argv[j][n])
					break ;
				n++;
			}
			if (argv[i][n] == 0 && argv[j][n] == 0)
				write_and_close();
			i++;
		}
		j++;
	}
}

t_list	**initialize_stack(t_list **stack_a, int argc, char **argv)
{
	int	i;

	i = 1;
	check_argvs(argc, argv);
	check_duplicates(argc, argv);
	stack_a = (t_list  **)malloc(sizeof(t_list *) * (argc - 1));
	if (!stack_a)
	{
		ft_lstclear(stack_a, NULL);
		exit(1);
	}
	*stack_a = NULL;
	while (i < argc)
	{
		ft_lstadd_back(stack_a, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	return(&(*stack_a));
}