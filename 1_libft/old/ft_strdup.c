/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/07/02 10:15:38 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/26 23:26:55 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* strdup 3 sey yapar
    1) bir buffer char* yaratıp ona yer parametre kadar yer ayırır
    2) parametreyi buffera kopyalar, sonuna null koyar
    3) bufferı döndürür
*/

char	*ft_strdup(const char *s1)
{
	char *my_str;
	size_t i;
	i = ft_strlen(s1);
	// uzunluk + null kadar yer ayırıyoruz
	my_str = (char *)malloc(sizeof(char) * i + 1);
	if (!my_str)
		return (my_str);
	// sonuna null koyuyoruz
	my_str[i] = '\0';
	// i kadar s1'i buffera kopyalıyoruz
	while (i--)
		my_str[i] = s1[i];
	// finalde de döndürüyoruz
	return (my_str);
}

/* int main()  {
    char x[] = "asd";
    ft_strdup(x);
    printf("%s", x);
} */