/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:02:14 by bkaramol          #+#    #+#             */
/*   Updated: 2023/06/04 02:12:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h> 
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_x(unsigned int nb);
int	print_capx(unsigned int nb);
int	print_p(unsigned long p);
int	print_c(char c);
int	print_s(char *str);
int	digit(int nb);
int	print_di(int nb);
int	print_u(unsigned int nb);
int	check(char c, va_list ap);

#endif
