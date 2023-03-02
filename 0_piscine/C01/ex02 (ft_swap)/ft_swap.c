/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:28:36 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:24:43 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* swap tekniği iki değişkenin değerlerinin yerini
değiştirmek istediğimizde kullanılır. 2 tane önemli özelliği vardır
	1) parametreleri pointer ile alması
	2) bir temp değişkenine ihtiyaç duyması
birincisinin sebebi eğer pointer yani pass by reference ile almazsa
ve normal alırsa:

void ft_swap(int a, int b) {
	int t;
	t = a;
	a = b;
	b = t;
}
buna pass by value denir. bu durumda asıl a ve b değişkenleriyle değil
onların yaratılmış kopyalarıyla işlem yapar. yani a'nın değerini kopyalar,
onu t'ye atar t'yi b'ye atar vs. vs. eğer a ve b'nin hafızadaki değerlerini
değiştirmek istiyosan adresleriyle işlem yapmalısın.
ikincisi de bir başka boş değişken kullanmak zorundayız (bu örnekte en azından)
yoksa diğer türlü
a = b
b = a
dersek b'yi a'ya atınca a'nın değeri kaybolur, 2. satırın bi anlamı kalmaz.
ek olarak bu t değişkenini * olarak tanımlayamama sebebimiz de bu değişkende
bir adres değil değer tutacak olmamız. o yüzden adres harici bi şey atamaya
calıstıgımızda hata verecektir. */

#include <unistd.h>

void ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// 2. yöntem. hafıza açısından daha verimli fakat less readable
// ^ ifadesi bit-changes (0sa 1 1se 0 yapiyor)
void ft_swap(int *a, int *b)
{
	*a ^= *b; // (1) a = a ^ b
	*b ^= *a; // (2) b = b ^ (a ^ b) = a
	*a ^= *b; // (3) a = (a ^ b) ^ a  = b  // a was set to a^b (1) and b became a (2)
}


// 3. yöntem pure arithmetic
void ft_swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

// 4. yöntem
void ft_swap(int *a, int *b)
{
	(*a ^= *b ^= *a ^= *b);
}
