/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:10:42 by ncolomer          #+#    #+#             */
/*   Updated: 2022/07/20 16:36:16 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// finds last element of a list

t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		// eğer devamında bir yapı (next) yoksa listenin
		// son elemanıdır o yüzden döndürüyoruz
		if (!lst->next)
			return (lst);
		// değilse -> next diyerek hep bir sonraki 
		// struct yapısına geçiyoruz
		lst = lst->next;
	}
	// bundan çıktığında da son elemanı bulmuş oluyor ve döndürüyoruz
	return (lst);
}
