/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:15:33 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:31:38 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Locates the last occurrence of a character in a string. 
 * Takes a string `str` and a character `ch` (as an integer) 
 * to search for. 
 * Iterates through the string and stores the pointer 
 * to the last occurrence of `ch`. 
 * Returns a pointer to the last occurrence of `ch` 
 * in the string, or NULL if `ch` is not found. 
 * Useful for reverse searches or handling 
 * the last appearance of a character in a string. 
 */

char	*ft_strrchr(const char *str, int ch)
{
	int		i;
	char	*caststr;
	char	*temp;

	i = 0;
	temp = NULL;
	caststr = (char *) str;
	while (caststr[i])
	{
		if (caststr[i] == (char) ch)
			temp = &caststr[i];
		i++;
	}
	if (caststr[i] == (char) ch)
		temp = &caststr[i];
	return (temp);
}
