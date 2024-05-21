/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:17:14 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 11:34:32 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0; // ya da '\0' but not NULL bc it is a constant pointer
		i++;
	}
}

/* ------------------- */

void printArr(char *a, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", a[i]);
	}
	printf("\n");
}

//int main()
//{
//	char *a = malloc(sizeof(int) * 5);
//	a[0] = 'b';
//	a[1] = 'u';
//	a[2] = 'g';
//	a[3] = 'r';
//	a[4] = 'a';
//	printArr(a, 5);
//	ft_bzero(a, 2);
//	printArr(a, 5);
//	free(a);
//}
