/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:58:28 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 15:58:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

t_arg	*p_lstlast(t_arg *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	p_lstadd_back(t_arg **lst, t_arg *new)
{
	t_arg	*list;

	list = p_lstlast((*lst));
	if (!list)
		*lst = new;
	else
		list->next = new;
}

void	p_lstadd_front(t_arg **lst, t_arg *new)
{
	new->next = *lst;
	*lst = new;
}

t_arg	*p_lstnew(int type, char *s)
{
	t_arg	*node;

	node = malloc(sizeof(t_arg));
	if (!node)
	{
		free(s);
		free(node);
		return (0);
	}
	node->arg = ft_strdup(s);
	node->type = type;
	node->next = NULL;
	free(s);
	return (node);
}

int	p_lstsize(t_arg *lst)
{
	int	i;

	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
