/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:30:14 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 11:46:28 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
	(*lst) = new;
}

/* ----------------------- */

int main()
{
	t_list *head = NULL;
	t_list *new1 = ft_lstnew("bir");
	t_list *new2 = ft_lstnew("iki");
	t_list *new3 = ft_lstnew("üç");

	ft_lstadd_front(&head, new1);
	ft_lstadd_front(&head, new2);
	ft_lstadd_front(&head, new3);
	while (head)
	{
		printf("%s ", (char *)head->content);
		head = head->next;
	}
	printf("\n");
}
