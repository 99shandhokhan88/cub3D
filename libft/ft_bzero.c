/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:01:18 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:54:28 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Sets a block of memory to zero. 
 * Takes a pointer `dest` to the memory area 
 * and a `len` specifying the number 
 * of bytes to set to zero. Internally uses `ft_memset` to achieve this. 
 * Does not return a value as 
 * it directly modifies the memory pointed to by `dest`. 
 * Commonly used to initialize or clear memory buffers. 
 */

void	ft_bzero(void *dest, size_t len)
{
	ft_memset(dest, 0, len);
}
