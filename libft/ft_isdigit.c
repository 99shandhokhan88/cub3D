/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzashev <vzashev@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:38:09 by vzashev           #+#    #+#             */
/*   Updated: 2025/01/21 01:30:14 by vzashev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * Checks if a character is a digit (0-9). 
 * Takes an integer `arg` as input, 
 * typically representing a character. 
 * Returns 1 if `arg` corresponds 
 * to an ASCII digit ('0' to '9'), otherwise returns 0. 
 * Commonly used for validating numeric input or processing digit characters. 
 * Assumes input is a valid ASCII value. 
 */

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}
