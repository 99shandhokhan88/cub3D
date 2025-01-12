/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 23:51:36 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/12 02:33:50 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int n)
{
	char	*char_n;
	int		len;

	char_n = ft_itoa(n);
	len = ft_printstr(char_n);
	free(char_n);
	return (len);
}

static void	recur_print_u(unsigned int n)
{
	if (n > 9)
	{
		recur_print_u(n / 10);
		recur_print_u(n % 10);
	}
	else
		ft_printchar(n + '0');
}

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

int	ft_printunsigned(unsigned int n)
{
	if (n == 0)
		return (ft_printchar('0'));
	recur_print_u(n);
	return (get_size(n));
}
