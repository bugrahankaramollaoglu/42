/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 22:23:02 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/19 22:23:03 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_variable(va_list list, const char a);
int	ft_put_char(int c);
int	ft_put_string(char *str);
int	ft_putnbr(int n);
int	ft_put_unumber(unsigned int n);
int	ft_hex(unsigned long p, char *base, int check, int base_len);

#endif
