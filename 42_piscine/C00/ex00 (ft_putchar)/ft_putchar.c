/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:52:51 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/12 17:55:24 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* fonksiyonun isminin solundaki şey o fonksiyonun döndüreceği değerin tipidir.
bir fonksiyonun bir şey döndürmesi demek bu fonksiyonun r-value olabilmesi yani bir denklikte
sağ tarafa yazılıp bir değişkene bu döndürdüğü değer (her ne ise) atılabilmesi demektir. döndürülen
değer ekrana yazdırılan değer demek değildir. printf() ve write() başka, return başka amaçla kullanılır.
fonksiyonun solunda void, int, char, char * olması demek o fonksiyonun sırasıyla bunları döndürmesi demektir.
parantez içine ise parametre(ler) yazılıyor. */

void ft_putchar(char x) {
    write(1, &x, 1);
}

/* write() fonksiyonunun default 3 modu var. bunlara FD (file descriptor) deniyor.
	* 0 - input (STDIN)
	* 1 - output (STDOUT)
	* 2 - error (STDERR)
   ortanca parametre adres alır ve o adresteki değeri yazdırır. char yazdıracaksak & ile adresi almalıyız
   char pointer yazdıracaksak & kullanmayız çünkü pointer'larda pointerın ismi direkt adresin başlangıcına tekabül eder:
	1) char myChar = 'a';
	   write(1, &myChar, 1);
	2) char *myString = "bugra";
	   write(1, myString, 5);
	üçüncü ve son parametre ise yazdıracagın byte sayıdır. mesela yukarıda 5 değil 3 deseydik bug yazdırırdı.
*/




