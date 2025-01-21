/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:22:54 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:29:16 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Fills a block of memory with a specified value. 
 * Takes a pointer `dest` to the memory area, 
 * an integer `value` (converted to unsigned char), 
 * and `len` specifying the number of bytes to set. 
 * Iterates over the memory block, 
 * setting each byte to `value`, and returns the original pointer `dest`. 
 * Commonly used for initializing or resetting memory areas. 
 */

void	*ft_memset(void *dest, int value, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) dest;
	while (len > 0)
	{
		*ptr = (unsigned char) value;
		ptr++;
		len--;
	}
	return (dest);
}
