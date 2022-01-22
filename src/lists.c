#include "../inc/pushswap.h"

t_list *ft_lstnew(int content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (0);
	elem->next = NULL;
	elem->content = content;
	return (elem);
}

void ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst && !(*lst))
	{
		new->next = NULL;
		*lst = new;
		return ;
	}
	new->next = *lst;	//в следующий элемент после new закидываем то, что лежало по адресу lst
	*lst = new; //по адресу lst располагаем то, что хранится в new
	return ;
}

int ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*ft_lstlast(t_list *lst)
{

	if (!lst)
		return (0);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*f;

	if (!new)
		return ;
	if (lst != 0 && *lst != 0)
	{
		f = ft_lstlast(*lst);	//записываем в f последний элемент списка
		f->next = new;
	}
	else
		*lst = new;
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(void)del;
	lst->next = NULL;
	free(lst);
	lst = NULL;
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*next;

	cur = *lst;
	while (cur)
	{
		next = cur->next;
		ft_lstdelone(cur, del);
		cur = next;
	}
	*lst = NULL;
}