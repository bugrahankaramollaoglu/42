/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 00:49:07 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/25 17:00:10 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    // liste bitene kadar
    while (begin_list)
    {
        // eğer data'sı boş değilse
        if (begin_list->data)
            // f() fonksiyonuna tabi tutuyoruz
            (*f)(begin_list->data);
        // ve bir sonraki elemana geçiyoruz
        begin_list = begin_list->next;
    }
}