/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 03:46:31 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/12 02:31:26 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned long long n)
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

static void	recur_print_p(unsigned long long n)
{
	if (n > 15)
	{
		recur_print_p(n / 16);
		recur_print_p(n % 16);
	}
	else if (n > 9)
		ft_printchar(n + 'a' - 10);
	else
		ft_printchar(n + '0');
}

int	ft_printpointer(unsigned long long n)
{
	if (n == 0)
		return (ft_printstr(NIL_STRING));
	ft_printstr("0x");
	recur_print_p(n);
	return (get_size(n) + 2);
}
