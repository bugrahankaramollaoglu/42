/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:05:17 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/26 01:17:10 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// creates a new element in the list

t_list *ft_lstnew(void *content)
{
	t_list *rt;

	// öncelikle yer açıyoruz
	rt = malloc(sizeof(t_list));
	// başarısız olmuşsa 0 döndürüyoruz
	if (!rt)
		return (0);
	// content olarak libft'de tanımladıgımız t_list'teki contenti atıyoruz
	rt->content = content;
	// sonrasında next'ini null yapıyoruz ki bitmiş olsun
	// çünkü listelerde yeni yapılar sondan ekleniyor
	rt->next = NULL;
	return (rt);
}

/* int main()
{
	t_list *a;
	a = malloc(sizeof(t_list));
	a->content = "bugra";
	a->next = NULL;
	printf("%s", a->content);
} */