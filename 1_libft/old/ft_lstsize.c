/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:28:48 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/19 17:27:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// counts elements of a list

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	// liste bitene kadar
	while (lst)
	{
		// her ->next'e geçilebildiğinde liste bitmemiş demektir
		// o zaman da eleman sayısını bir arttırıyoruz
		// liste bittiğinde döngüden çıkıp i'yi döndürüyor
		lst = lst->next;
		i++;
	}
	return (i);
}
