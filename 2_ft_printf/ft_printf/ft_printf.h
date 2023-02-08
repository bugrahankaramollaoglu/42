/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 22:08:33 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/08 15:20:17 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf_lowerx(unsigned long x);
int		ft_printf_upperx(unsigned long x);
size_t	ft_strlen(const char *s);
int		ft_printf_putchar(char c);
int		ft_printf_unsigned(unsigned int u);
int		ft_printf_putnbr(int nb);
int		ft_printf_print_ptr(unsigned long ptr);
int		ft_printf_putstr(char *str);
int		checker(int c, va_list ap);
int		ft_printf(const char *param, ...);

#endif
