/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:44:44 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/24 15:30:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// deletes sequence of elements of the list from a starting point
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	// herhangi birisi boşsa return ;
	if (!del || !lst || !*lst)
		return ;
	// liste ve *listenin gösterdiği ilk eleman bitene kadar
	while (lst && *lst)
	{
		// önce lst'nin point ettiği yerden sonraki elemanı geçiciye at
		tmp = (*lst)->next;
		// sonra delone() fonksiyonu yardımıyla sil lst'yi sil
		ft_lstdelone(*lst, del);
		// daha sonra tempdeki dosyayı lst'ye geri at ki silindikten sonra liste devam etsin
		*lst = tmp;
	}
}
