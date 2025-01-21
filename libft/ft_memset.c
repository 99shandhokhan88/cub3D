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
