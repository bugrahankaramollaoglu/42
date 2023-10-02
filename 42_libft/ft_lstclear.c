/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:33:00 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 11:50:37 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *tmp;

	if (!del || !lst || !*lst)
		return;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/* ------------------------------ */

void myDel(void *content)
{
	if (content)
		free(content);
}

int main()
{
	t_list *head = NULL;
	t_list *new1 = ft_lstnew("bir");
	t_list *new2 = ft_lstnew("iki");
	t_list *new3 = ft_lstnew("üc");

	ft_lstadd_back(&head, new1);
	ft_lstadd_back(&head, new2);
	ft_lstadd_back(&head, new3);

	printf("before: \n");
	while (head)
	{
		printf("%s ", (char *)head->content);
		head = head->next;
	}
	printf("\n");

	ft_lstclear(&head, myDel);

	printf("now: \n");
	while (head)
	{
		printf("%s ", (char *)head->content);
		head = head->next;
	}
	printf("\n");
}
