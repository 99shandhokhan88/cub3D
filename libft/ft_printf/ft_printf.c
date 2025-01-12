/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:04:52 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/12 02:40:06 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(args, int));
	if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	if (c == 'p')
		len += ft_printpointer(va_arg(args, unsigned long long));
	if (c == 'd')
		len += ft_printnbr(va_arg(args, int));
	if (c == 'i')
		len += ft_printnbr(va_arg(args, int));
	if (c == 'u')
		len += ft_printunsigned(va_arg(args, unsigned int));
	if (c == 'x')
		len += ft_printhex(va_arg(args, unsigned int), c);
	if (c == 'X')
		len += ft_printhex(va_arg(args, unsigned int), c);
	if (c == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += check_type(args, str[i + 1]);
			i++;
		}
		else
		{
			ft_printchar(str[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
