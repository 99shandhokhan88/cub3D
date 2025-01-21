/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 22:32:20 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:55:28 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Allocates and initializes memory to zero. 
 * Takes two arguments: `n` (number of elements) 
 * and `size` (size of each element in bytes). 
 * Allocates memory for `n * size` bytes using `malloc` 
 * and initializes the block to zero using `ft_bzero`. 
 * Returns a pointer to the allocated memory, 
 * or NULL if allocation fails or the size is invalid. 
 * Useful for dynamically allocating zero-initialized arrays or structures. 
 */

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;

	if (n && size && n > (4294967295 / size))
		return (NULL);
	ptr = malloc(size * n);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * n);
	return (ptr);
}
