/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:23:31 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/24 14:26:35 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* s1 ile s2 stringini karşılaştırır. farklı olan ilk karakterin ascii farkını döndürür */
int ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] || s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>

/* a b ve c aynı oldugu icin while boyunca arttırdı. aynı olmadıgında (s1[i] == s2[i] saglanmadıgında)
döngüden çıktı ve return ile farklarını döndürdü (d-t = 16) */
int main()
{
	char a[] = "abcd";
	char b[] = "abct";
	printf("%d\n", ft_strcmp(a, b));
}

/* strcmp'de mühim olan ne döndürdüğün değil, +, - ya da 0 bir değer döndürmen. o yüzden
s1[i] - s2[i] yerine eğer s1>s2 ise return (1), küçükse return (-1) de diyebilirdin. bilgisayar
sadece işaretine bakıyor çünkü. */
