/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:41 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/18 17:42:34 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str) {
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_strjoin(int size, char **strs, char *sep) {
	if (size == 0)
	{
		char *str;
		return str;
	}
	
