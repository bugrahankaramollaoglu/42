/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:16:43 by ncolomer          #+#    #+#             */
/*   Updated: 2022/07/24 15:30:16 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// deletes element from the list
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del)
		return ;
	// lst bitene kadar
	if (lst)
	{
		// del fonksiyonu ile önce lst'in içeriğini sil
		(*del)(lst->content);
		// daha sonra free ile ona ayrılmış yeri serbest bırak
		free(lst);
	}
}
