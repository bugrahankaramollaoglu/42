/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:44:30 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 17:02:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// listeye sondan n elemanını ekleme

void ft_lstadd_back(t_list **alst, t_list *new)
{
	// listenin son elemanını tutacak bi degisken yaratiyoruz
	t_list *last_elem;

	if (!new)
		return;

	// eğer boşsa direkt new'i atabiliriz icine
	// cünkü her halükârda sonuncu eleman olmuş olur
	if (!*alst)
	{
		*alst = new;
		return;
	}

	// sondan eklemek için sondaki elemanı bulmamız gerekiyor
	last_elem = ft_lstlast(*alst);
	// lstlast() [son elemanı bulma] fonksiyonu
	// yardimiyle *alst'in son elemanını last_elem'e atar
	// daha sonra last_elem'den bir sonraki yapıya new'i yani
	// listenin sonuna eklemek istediğimiz elemanı atar
	last_elem->next = new;
	new->next = NULL;
}

typedef struct Node
{
	int data;
	struct Node *next;
} myNode;

int main()
{
	myNode *first;
	myNode *second;
	myNode *third;
	// myNode *fourth;

	first = (struct Node *)malloc(sizeof(struct Node));
	second = (struct Node *)malloc(sizeof(struct Node));
	third = (struct Node *)malloc(sizeof(struct Node));
	// fourth = (struct Node *)malloc(sizeof(struct Node));

	first->data = 10;
	first->next = second;

	second->data = 20;
	second->next = third;

	third->data = 30;
	third->next = NULL;
}