/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:44:23 by flo-dolc           #+#    #+#             */
/*   Updated: 2025/01/21 01:29:36 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	srclen;

	srclen = ft_strlen(src);
	dup = (char *) malloc(sizeof(char) * srclen + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, src, srclen + 1);
	return (dup);
}
