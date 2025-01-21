/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 02:39:36 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:30:39 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Copies a string into a destination buffer 
 with size protection (`ft_strlcpy`). 
 * Takes a destination pointer `dest`, 
 * a source string `src`, and a `size` specifying the buffer size. 
 * Copies up to `size - 1` characters 
 * and null-terminates the result. 
 * Returns the total length of the source string (`srclen`), 
 * allowing buffer size checks. 
 * Ensures safety when copying strings into fixed-size buffers. 
 */

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (src_len);
}

/* 
 * Copies up to `n` characters from `src` to `dest` (`ft_strncpy`). 
 * Takes a destination pointer `dest`, a source string `src`, 
 * and the maximum number of characters `n` to copy. 
 * Pads the rest of the destination with null bytes if `n` exceeds 
 * the length of `src`. 
 * Returns the destination pointer `dest`. 
 * Useful for fixed-length copying, including padding. 
 */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
