/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 19:58:07 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:28:05 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Converts a string to an integer (ASCII to integer). 
 * Takes a string `str` as input and processes leading whitespace, 
 * an optional sign (+/-), 
 * and numerical digits to calculate the integer value. 
 * Returns the resulting integer, considering the sign. 
 * Handles edge cases like non-numeric characters gracefully
 * by stopping conversion. 
 * Assumes input is well-formed and does not handle overflow explicitly.
 */

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	return (res * sign);
}
