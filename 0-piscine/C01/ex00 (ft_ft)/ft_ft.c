/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:41:01 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:10:58 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* Create a function that takes a pointer to 
int as a parameter, and sets the value "42"
to that int */

#include <unistd.h>

void    ft_ft(int *nbr)
{
	*nbr = 42;
}

/* 
int a;
*a --> is a pointer to int
 */