
#include "../include/cub3D.h"

t_file	*lstnew(char *line)
{
	t_file	*new;

	new = (t_file *)malloc(sizeof(t_file));
	if (new == NULL)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

t_file	*lstlast(t_file *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_file **lst, t_file *new)
{
	t_file	*p;

	if (lst == NULL || new == NULL)
		return ;
	p = *lst;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = lstlast(*lst);
		p->next = new;
	}
}
