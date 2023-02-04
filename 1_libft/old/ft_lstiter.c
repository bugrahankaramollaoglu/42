/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 15:32:31 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/24 15:32:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies a certain function to all of the content of list's elements
// ama bunu listeyi bir buffera atmadan yapar, direkt string üzerinde işlem uygular

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	// eğer fonksiyon boşsa return ;
	if (!f)
		return ;
	// yoksa liste bitene kadar
	// (*f) fonksiyonunu lst'in her contentine uygula
	// daha sonra lst->next ile listenin bir sonraki elemanına geç
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}
