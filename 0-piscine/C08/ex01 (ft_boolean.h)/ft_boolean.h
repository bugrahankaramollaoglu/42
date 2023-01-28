/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 09:12:17 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/28 09:17:13 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define EVEN_MSG "I have a pair num of arguments.\n"
# define ODD_MSG "I have an impair num of arguments.\n"
# define EVEN(n) ((n % 2 == 0) ? TRUE:FALSE

void		ft_putstr(char *str);
typedef int	t_bool;
t_bool		ft_is_even(int nbr);

#endif
