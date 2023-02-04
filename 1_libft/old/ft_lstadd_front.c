/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 11:44:38 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 17:06:07 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// listeye baştan eleman ekleme
void	ft_lstadd_front(t_list **alst, t_list *new)
{
	// if alst != 0
	if (alst)
	{
		// alst'in point ettiği şey boş değilse o zaman new'in bir sonraki kutucuguna
		// *alst'yi yani ilk kutucuğu koyacak bir kod yazabilirsin
		// bu durumda new ilk kutudan da önce gelir ve baştan itibaren 
		// listeye eleman eklemiş oluruz
		if (*alst)
			new->next = *alst;
		// daha sonra new'ü alst'in pointerına atarak
		// listenin başlangıcını new yapmış oluyoruz
		*alst = new;
	}
}
