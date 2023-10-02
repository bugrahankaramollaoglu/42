/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:37:03 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 13:18:18 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int counter;

	counter = 0;
	while (lst)
	{
		++counter;
		lst = lst->next;
	}
	return (counter);
}

/* ------------------------------------ */

int main()
{
	t_list *head = NULL;
	t_list *second = NULL;
	t_list *third = NULL;

	head = (t_list *)malloc(sizeof(t_list));
	second = (t_list *)malloc(sizeof(t_list));
	third = (t_list *)malloc(sizeof(t_list));

	// burada content void ptr aldıgı icin constant string
	// ya da integerin adresi atayabiliriz. çünkü constantStr'ler
	// direkt pointer olarak calısırlar.
	head->content = "head";
	head->next = second;

	int valForSec = 12;
	second->content = &valForSec;
	second->next = third;

	float valForThird = 32.5f;
	third->content = &valForThird;
	third->next = NULL;

	int size = ft_lstsize(head);

	printf("size is: %d\n", size);

	free(head);
	free(second);
	free(third);
}
