/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 03:06:05 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/08 14:56:57 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int swap;
    t_list *tmp;

    tmp = lst;
    while (lst->next)
    {
        if (((*cmp)(lst->data, lst->next->data)) == 0)
        {
            swap = lst->data;
            lst->data = lst->next->data;
            lst->next->data = swap;
            lst = tmp;
        }
        else
            lst = lst->next;
    }
    lst = tmp;
    return (lst);
}

