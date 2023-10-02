/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:32:34 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 12:36:13 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return;
	if (lst)
	{
		(*del)(lst->content);
		free(lst);
	}
}

/* --------------------------------- */

void myDel(void *content)
{
	if (content)
		free(content);
}

int main() {
	t_list *new1 = ft_lstnew("bir");
	t_list *new2 = ft_lstnew("iki");
	t_list *new3 = ft_lstnew("üç");

	ft_lstdelone(new1->next, myDel);
}


