/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:32:38 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 13:16:22 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/* ----------------------------------- */

void printContent(void *content)
{
	printf("%s ", (char *)content);
}

int main()
{
	t_list *head = NULL;
	t_list *new1 = ft_lstnew("one");
	t_list *new2 = ft_lstnew("two");
	t_list *new3 = ft_lstnew("three");

	ft_lstadd_back(&head, new1);
	ft_lstadd_back(&head, new2);
	ft_lstadd_back(&head, new3);

	ft_lstiter(head, printContent);
	printf("\n");

	free(new1);
	free(new2);
	free(new3);

	return 0;
}
