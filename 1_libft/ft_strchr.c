/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:54:51 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/01 15:33:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c) {
	if (s == NULL)
		return 0;
	if (c == NULL)
	{
		while (*s)
			s++;
		return (s+1);
	}
	else {
		while (*s) {
			if (*s == c)
		}

	}
}
