/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:32:30 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 13:16:10 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/* -------------------------------------- */

int main()
{
	t_list *head = NULL;
	t_list *new1 = ft_lstnew("bir");
	t_list *new2 = ft_lstnew("iki");
	t_list *new3 = ft_lstnew("üç ve son");

	ft_lstadd_back(&head, new1);
	ft_lstadd_back(&head, new2);
	ft_lstadd_back(&head, new3);

	t_list *lastNode = ft_lstlast(head);
	printf("%s\n", (char *)lastNode->content);
}
