/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:01:00 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/20 20:39:47 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_file	*list_new(char *line)
{
	t_file	*new;

	new = (t_file *)malloc(sizeof(t_file));
	if (new == NULL)
		return (NULL);
	new->line = line;
	new->next = NULL;
	return (new);
}

t_file	*list_last(t_file *lst)
{
	if (lst == NULL)
		return (lst);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	list_add_back(t_file **lst, t_file *new)
{
	t_file	*p;

	if (lst == NULL || new == NULL)
		return ;
	p = *lst;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		p = list_last(*lst);
		p->next = new;
	}
}
