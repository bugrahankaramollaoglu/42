/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 21:30:17 by bkaramol          #+#    #+#             */
/*   Updated: 2023/04/28 00:08:06 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *ft_buff(int fd, char *str)
{
	// basariyla okunmus byte sayısı
	int rd_bytes;

	// BUFFER_SIZE'ar kadar okunmus seylerin atılacagi char stringi
	char *buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	if (!buff)
		return (NULL);

	// 1'in özel bir sebebi yok 0 ya da -1 olmasın istiyoruz sadece
	rd_bytes = 1;
	// \n görene kadar bu çalışıyor (her bir satırın sonunda \n var)
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
		// read(a, b, c) fonksiyonu a'dan b'ye c byte kadar
		// okuma işlemi yapıyor. 3 şey döndürebilir
		// *) 0 --> EOF gelmiştir
		// **) -1 --> hata vermiştir
		// ***) ya da 1 ve üstü --> başarılı okudugu byte sayısını berir
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(str);
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

// fd id'li dosyayı satır satır okuyan fonksiyon
char *get_next_line(int fd)
{
	// o anki satırı tutacak char string
	char *line;

	// str, \n görene kadar buffer kadar
	// okunan şeylerin atıldığı char stringi
	static char *str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	str = ft_buff(fd, str);
	if (!str)
		return (NULL);
	printf("--str-->  %s\n", str);

	line = ft_get_line(str);
	printf("--line--> %s\n", str);

	str = ft_last_str(str);
	printf("--kalan-str--> %s\n", str);

	return (line);
}

int main()
{
	char *metin;

	// yaratıp izin veriyoruz
	int fd = open("abc.txt", O_CREAT | O_RDWR, 777);

	metin = get_next_line(fd);

	while (metin)
	{
		// printf("%s", metin);
		free(metin);			   // bunu koymazsan valgrindde leaks veriyor
		metin = get_next_line(fd); // her kullanışta bir sonraki satiri aliyoruz
	}
	// system("leaks a.out");
}
