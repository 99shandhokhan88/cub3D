/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 20:01:00 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:32:50 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Functions to manage a linked list of `t_file` structures. 
 * `list_new` creates a new node 
 * with a `line` string and returns a pointer to it. 
 * `list_last` traverses the list 
 * to find and return the last node. 
 * `list_add_back` appends 
 * a new node to the end of the list. 
 * It handles the case when the list is empty or non-empty. 
 * Useful for managing dynamic collections 
 * of strings or file-related data in a linked list structure. 
 */

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
