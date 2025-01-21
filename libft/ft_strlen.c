/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 03:00:06 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:30:55 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Calculates the length of a string. 
 * Takes a pointer `str` to a null-terminated string as input. 
 * Iterates through the string, 
 * counting characters until the null terminator is encountered. 
 * Returns the length of the string (number of characters excluding 
 * the null terminator). 
 * Commonly used to determine the size of a string before processing. 
 */

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
