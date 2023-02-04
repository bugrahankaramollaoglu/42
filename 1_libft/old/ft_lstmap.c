/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:25:31 by ncolomer          #+#    #+#             */
/*   Updated: 2022/07/25 12:27:30 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// applies a certain function to all of the contents of list's elements but into a new list (buffer)
// lstiteri'den farkı budur. iteri direkt stringi değiştirir.

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*buffer;
	t_list	*temp;

	// herhangi birisi boşsa null döndür
	if (!lst || !f)
		return (NULL);

	// finalde döndüreceğimiz fresh list
	buffer = NULL;
	while (lst)
	{
		// lstiteri'den farklı olarak yeni bir liste
		// yarattığı için lstnew() ile lst boyunca yeni elemanlar yaratıp
		// content'ini attığımız lst'i (*f)'e tâbi tutuyoruz
		temp = ft_lstnew((*f)(lst->content));
		// eğer temp nullsa lstclear() yardımiyle 
		// adresini del() ile siliyoruz ve çıkıyoruz fonksiyondan
		if (!temp)
		{
			ft_lstclear(&buffer, del);
			return (NULL);
		}
		// yok değilse (değerini) temp'e ekliyoruz
		ft_lstadd_back(&buffer, temp);
		// attıktan sonra aşagıdaki komut yardimiyle bir sonraki liste 
		// yapısına geçiyoruz
		temp = temp->next;
		// daha sonra temp gibi listeyi de bir atlatıyoruz ki aynı şeyi atip durmasin
		lst = lst->next;
		// bu lst bitene kadar yani tüm elemanlar boyunca sürüyor
	}
	// finalde de içini doldurduğumuz yeni listeyi döndürüyoruz
	return (buffer);
}
