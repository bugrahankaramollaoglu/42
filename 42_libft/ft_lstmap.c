/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:32:49 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 13:16:45 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *buffer;
	t_list *temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	buffer = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstclear(&buffer, del);
			free(temp);
			return (NULL);
		}
		ft_lstadd_back(&buffer, temp);
		temp = temp->next;
		lst = lst->next;
	}
	return (buffer);
}

void *doubleVal(void *content)
{
	int *val = (int *)content;
	int *newVal = (int *)malloc(sizeof(int));
	if (!newVal)
		return 0;
	*newVal = (*val) * 2;
	return (void *)newVal;
}

void deleteNode(void *content)
{
	if (content)
		free(content);
}

int main()
{
	t_list *head = NULL;
	t_list *second = NULL;
	t_list *third = NULL;

	int value1 = 5;
	int value2 = 10;
	int value3 = 15;

	head = ft_lstnew(&value1);
	second = ft_lstnew(&value2);
	third = ft_lstnew(&value3);

	ft_lstadd_back(&head, second);
	ft_lstadd_back(&head, third);

	t_list *doubledList = ft_lstmap(head, doubleVal, deleteNode);

	printf("Original list: ");
	t_list *current = head;
	while (current)
	{
		int *value = (int *)current->content;
		printf("%d ", *value);
		current = current->next;
	}
	printf("\n");

	printf("Doubled list: ");
	current = doubledList;
	while (current)
	{
		int *value = (int *)current->content;
		printf("%d ", *value);
		current = current->next;
	}
	printf("\n");

	ft_lstclear(&head, deleteNode);
	ft_lstclear(&doubledList, deleteNode);

	return 0;
}
