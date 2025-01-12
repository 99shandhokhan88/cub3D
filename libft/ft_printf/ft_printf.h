/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flo-dolc <flo-dolc@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 02:05:35 by flo-dolc          #+#    #+#             */
/*   Updated: 2024/03/12 02:40:06 by flo-dolc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft.h"

# ifdef __APPLE__
#  define NIL_STRING "0x0"
# endif
# ifdef __unix__
#  define NIL_STRING "(nil)"
# endif

int		ft_printf(const char *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printnbr(int n);
int		ft_printhex(unsigned int n, char c);
int		ft_printunsigned(unsigned int n);
int		ft_printpointer(unsigned long long n);

#endif
