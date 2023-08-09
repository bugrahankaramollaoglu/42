/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 12:03:04 by bkaramol          #+#    #+#             */
/*   Updated: 2023/06/04 02:15:22 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int check(char c, va_list ap)
{
	int ret;

	ret = 0;
	if (c == 'c')
		ret += print_c(va_arg(ap, int));
	else if (c == 's')
		ret += print_s(va_arg(ap, char *));
	else if (c == 'd' || c == 'i')
		ret += print_di(va_arg(ap, int));
	else if (c == 'u')
		ret += print_u(va_arg(ap, unsigned int));
	else if (c == 'x')
		ret += print_x(va_arg(ap, unsigned int));
	else if (c == 'X')
		ret += print_capx(va_arg(ap, unsigned int));
	else if (c == 'p')
	{
		ret += print_s("0x"); // UNIX'lerde hexadecimal sayilarin basında 0x bulunur
		ret += print_p(va_arg(ap, unsigned long));
	}
	else if (c == '%')
		ret += print_c('%');
	return (ret);
}

// ... variadic fonksiyon oldugu icin
int ft_printf(const char *str, ...)
{
	// toplamda yazdırılan byte sayısı döndürülecek. bu onu tutuyor
	int ret;
	// indis
	int i;
	// o anki parametreyi tutacak
	va_list ap;

	ret = 0;
	i = 0;
	// parametreleri işleme işlemini başlatıyoruz
	va_start(ap, str);
	while (str[i])
	{
		// yüzde işaretini gördügü anda girmeli ki karakter olarak yazdırmasın
		if (str[i] == '%')
		{
			i++;
			ret += check(str[i], ap);
		}
		else
			ret += print_c(str[i]);
		i++;
	}
	// ret olayının sebebi klasik printf yazdırdıgı byte sayısını döndürüyor, biz de öyle yapiyoruz
	return (ret);
}

int main(void)
{
	ft_printf("%d\n", 19);
	ft_printf("%d\n", 20);
	ft_printf("%u\n", 10);
	ft_printf("%x\n", 10);
	ft_printf("%X\n", 10);
	ft_printf("innuendo\n");
	system("leaks a.out"); // + valgrind ./a.out
}
