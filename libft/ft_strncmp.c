/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:31:05 by flo-dolc          #+#    #+#             */
/*   Updated: 2025/01/21 01:53:30 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Compares two strings up to `n` characters. 
 * Takes two strings `s1` and `s2`, 
 * and a size `n` as input. 
 * Compares the strings character by character until 
 * a difference is found or `n` characters are compared. 
 * Returns a positive, negative, or zero value based on 
 * the lexicographical difference of the strings. 
 * Useful for partial string comparisons or sorting. 
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
		i++;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
