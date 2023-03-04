/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:33:20 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/24 14:27:17 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* destin sonuna src ekliyor. */
char *ft_strcat(char *dest, char *src)
{
	int a;
	int b;

	a = 0;
	/* destin sonuna ekleyeceğimiz için destin sonunu öğrenmemiz gerekiyor. bu durumda a'yı
	dest kadar arttırmasaydık ve 0 olsaydı src dest'e sonundan eklemek yerine başından (değiştirerek belki de)
	kopyalama yapardı. */
	while (dest[a])
	{
		a++;
	}
	b = 0;
	while (src[b])
	{
		dest[a] = src[b];
		a++;
		b++;
	}
	/* sonuna null ekliyoruz ki string olsun. C'de string ile char array arasında fark vardır.
	char array şu olabilir: char a[] = {'a','l','i'}; fakat bu bir string olmaz. string olması için
	sonunda null olması lazım. C'de 6 farklı şekilde string yaratılabilir:
		1) char a[] = "bugra";
		2) char a[en_az_5] = "bugra";
		3) char *a = "bugra";
		4) char *a = malloc(sizeof(char) * 5);
		   a = "bugra";
		5) char *a = malloc(sizeof(char) * 5);
		   a[0] = 'b';
		   a[1] = 'u';
		   a[2] = 'g';
		   a[3] = 'r';
		   a[4] = 'a';
		   a[5] = '\0';
		   tek tek atiyacaksak sonuna manuel \0 koymalısın diğerleri otomatik atiyor
		6) char a[] = {'b','u','g','r','a','\0'};
		*/
	dest[a] = '\0';
	return (dest);
}

int main()
{
	char a[] = "bugra";
	char b[] = "cemre";
	printf("%s\n", ft_strcat(a, b)); // bugracemre
}
