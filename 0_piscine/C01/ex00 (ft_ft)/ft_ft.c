/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 19:41:01 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:10:58 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* Create a function that takes a pointer to
int as a parameter, and sets the value "42"
to that int */

#include <unistd.h>

void    ft_ft(int *nbr)
{
	*nbr = 42;
}

/*
pointerlar tanımladıgımız bir değişkenin, fonksiyonun ya da structın vs. vs. isminin ve değerlerinin
hafızada (RAM'de) saklandığı hücre blogunun adresini tutan özel tipte değişkenlerdir. yani kısaca 16'lık formatta
adres tutan değişkenlerdir. iki tane operatörü vardır (* ve &).
	yıldız (*) operatörünün 2 işlevi vardır
		1) yaratılan değişkenin normal bir degisken olmadıgını, pointer bir degisken oldugunu
		   haliyle yalnızca geçerli bir adres tutabilecegini belirtirken kullanılır:
		   -> int *aPtr;
		   -> char *myName;
		   -> struct Node *myNode;
		2) dereferencing denilen olay. bir pointer tanımladıktan sonra * + pointerın_ismi yoluyla o pointerın gösterdiği
		   adresteki değere ulaşabiliriz.
			  int a = 50;
			  int *aPtr = &a;
			  printf("%d", *aPtr); --> 50 verir
	ampersand (&) operatörünün tek bi islevi vardır, adres almak
		-> int a = 50;
		   &a --> 0x12F500 gibi bir sayıdır.

basit pointer kullanımı

bir degisken yaratıyoruz
int a = 50;

buna pointer atıyoruz
int *aPtr = &a;

printf("%p\n", aPtr); >>> 0x7ffe66f20b7c (adres yazdırdı)
printf("%d\n", *aPtr); >>> 50 (a pointerının tuttugu adresteki değer) */
