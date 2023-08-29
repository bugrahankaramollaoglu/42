/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:56:32 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/22 21:09:48 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* If the size of the destination buffer is less than or equal to the length
of the source string, the function copies n - 1 characters from the source
string to the destination buffer and appends a null terminator at the end.
If the size of the destination buffer is greater than the length of the
source string, the function copies the entire source string to the
destination buffer and appends a null terminator at the end.*/
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	counter;

	index = 0;
	counter = 0;
	while (src[counter])
		counter++;
	if (size)
	{
		while (src[index] != '\0' && index < (size - 1))
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	return (counter);
}

/* The advantage of using strlcpy over strcpy is that it helps
prevent buffer overflows, which can occur when a string is
copied to a buffer that is too small to hold it. */

/* örnek

int main() {
	char src[] = "Hello, world!";
	char dest[6];
	ft_strlcpy(dest, src, sizeof(dest));
	printf("The value of dest is \"%s\"\n", dest);
}

bu kod <The value of dest is "Hello"> yazdırır. çünkü 5 hellodan 1 de null'dan
en fazla 6 byte kopyalanabilir. */

/* strlcpy ve strncpy farkı nedir?
strncpy fonksiyonu, srcnin ilk n karakterini deste kopyalar.
Eğer src n karakterden kısa ise, kalan bölüm null karakteri ile
doldurulur. Eğer src n karakterden uzun ise, deste yalnızca
n karakter kopyalanır. Ancak, sonuna null karakteri eklenmezse, hedef dizi
null karakteri ile sonlandırılmamış olur.
Öte yandan, strlcpy fonksiyonu, srcnin tümünü deste kopyalar
(veya srcnin tamamını kopyalayacak kadar alan yoksa, srcnin
boyutu kadar kopyalar) ve null karakteri de sonuna ekler. Bu nedenle, hedef
dizi her zaman null karakteri ile sonlandırılır.
Bu nedenle, strncpy fonksiyonunun kullanımı biraz dikkat gerektirir. Çünkü,
null karakteri ekleme işlemi, destin boyutunu belirlemede kullanılan n
sayısından bağımsız olarak gerçekleşir. Bu, hedef dizinin sonunda beklenmedik
karakterlerin kalması veya null karakterinin olmaması gibi sorunlara neden
olabilir. Öte yandan, strlcpy fonksiyonu srcnin tamamını kopyalar
ve null karakteri sonuna ekleyerek destin güvenli bir şekilde sonlandırılmasını
sağlar. Bu nedenle, strlcpy fonksiyonu, destin boyutunun belirlenmesi açısından daha güvenlidir. */
