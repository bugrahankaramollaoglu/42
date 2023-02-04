/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 03:52:56 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/19 08:13:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// This function writes the string s to the file descriptor fd followed by a
// '\n' to make a new line. 

void	ft_putendl_fd(char const *s, int fd)
{
    // eğer boşsa hiçbir şey yapmıyoruz
    // 0 bile döndürmüyoruz
	if (!s)
		return ;
    // önce s'yi yazdırıyoruz dosyaya
    // sonra new line yazdırıyoruz
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}


/* #include <fcntl.h>
int main()
{
    int fd = open("abc.txt", O_CREAT | O_RDWR);
    printf("%d\n", fd);
    write(fd, "test", 4);
    char y[] = "bugra";
    ft_putendl_fd(y, 2);
} */