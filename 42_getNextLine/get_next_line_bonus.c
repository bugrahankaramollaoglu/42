/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:01:40 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/12 01:01:40 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char *ft_buff(int fd, char *str)
{
	int rd_bytes;
	char *buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(str, '\n') && rd_bytes != 0)
	{
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

char *get_next_line(int fd)
{
	char *line;
	// maksimum 1024 adet fd açabilir
	// normal GNL'de sadece tek bir fd'den yani dosyadan
	// okuma yapabiliyoduk. bonusunda ise birden fazla fd'nin
	// içeriğini (şu an max 1024) okuyabiliyoruz ve çift boyutlu
	// bir dizide tutabiliyoruz
	static char *str[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str[fd] = ft_buff(fd, str[fd]);
	if (!str[fd])
		return (NULL);
	line = ft_get_line(str[fd]);
	str[fd] = ft_last_str(str[fd]);
	return (line);
}

/* int main()
{
	// yaratıp izin veriyoruz
	int fd1 = open("text1.txt", O_CREAT | O_RDWR, 777);
	int fd2 = open("text2.txt", O_CREAT | O_RDWR, 777);
	int fd3 = open("text3.txt", O_CREAT | O_RDWR, 777);

	if (!fd1 || !fd2 || !fd3)
		exit(1);

	// system("leaks a.out"); // + valgrind ./a.out
} */
