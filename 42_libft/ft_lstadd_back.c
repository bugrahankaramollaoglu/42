/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:26:40 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 11:42:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *last;

	if (*alst == NULL)
	{
		*alst = new;
		return;
	}
	last = ft_lstlast(*alst);
	last->next = new;
}

/* ---------------- */

// int main()
// {
// 	t_list *head = NULL;
// 	t_list *new1 = ft_lstnew("bir");
// 	t_list *new2 = ft_lstnew("iki");
// 	t_list *new3 = ft_lstnew("üç");

// 	ft_lstadd_back(&head, new1);
// 	ft_lstadd_back(&head, new2);
// 	ft_lstadd_back(&head, new3);

// 	while (head)
// 	{
// 		printf("%s ", (char *)head->content);
// 		head = head->next;
// 	}
// 	printf("\n");
// }
