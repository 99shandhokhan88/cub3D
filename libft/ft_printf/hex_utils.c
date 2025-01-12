/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 02:04:57 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/12 02:40:06 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

static void	recur_print_h(unsigned int n, char c)
{
	if (n > 15)
	{
		recur_print_h(n / 16, c);
		recur_print_h(n % 16, c);
	}
	else if (n > 9 && c == 'x')
		ft_printchar(n + 'a' - 10);
	else if (n > 9 && c == 'X')
		ft_printchar(n + 'A' - 10);
	else
		ft_printchar(n + '0');
}

int	ft_printhex(unsigned int n, char c)
{
	if (n == 0)
		return (ft_printchar('0'));
	recur_print_h(n, c);
	return (get_size(n));
}
