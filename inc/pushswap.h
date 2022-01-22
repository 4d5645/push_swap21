#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

t_list *ft_lstnew(int content);
void ft_lstadd_front(t_list **lst, t_list *new);
int ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	check_digits(int argc, char **argv);
void	check_ints(int argc, char **argv);
void	check_duplicates(int argc, char **argv);
t_list	**initialize_stack(t_list **stack_a, int argc, char **argv);
void    write_and_close();
void	swap(t_list **stack);
void	push(t_list **stack_dest, t_list **stack_src);
void	rotate(t_list **stack);
void	reverse_rotate(t_list **stack);
void    ss(t_list **stack_a, t_list **stack_b);
void    rr(t_list **stack_a, t_list **stack_b);
void    rrr(t_list **stack_a, t_list **stack_b);
void    sort_three(t_list **stack);



#endif