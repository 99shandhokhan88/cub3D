/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 13:12:02 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:31:54 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Extracts a substring from a given string. 
 * Takes the string `str`, a starting index `start`, 
 * and the length `len` of the substring to extract. 
 * Allocates memory for the new substring 
 * and copies characters from `str` starting at `start` for `len` characters. 
 * Returns the new substring, 
 * or NULL if allocation fails or invalid parameters are provided. 
 * Useful for extracting specific parts of a string. 
 */

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	if (start > (size_t) ft_strlen(str))
		return (ft_strdup(""));
	if (len > (size_t) ft_strlen(str))
		len = (size_t) ft_strlen(str);
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && start < (size_t) ft_strlen(str))
	{
		sub[i] = str[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
