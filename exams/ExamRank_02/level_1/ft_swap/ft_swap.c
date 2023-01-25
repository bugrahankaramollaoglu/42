/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:01:22 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/13 10:44:01 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// a ve b pointerlarının adreslerindeki değerleri değiştirebilmek için
// call by reference yapıyoruz. bunu da * yani dereference operatörüyle yapıyoruz
// temp = a, a = b; dersen sadece koddaki degiskenler degisir, asıl adreste değerleri aynı kalır
// ayrıca swap isleminde her zaman bir ücüncü temp'e ihtiyacın var ilk atadıgın deger kaybolmasın diye

void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
